#include "Epoll.h"
#include "TcpConnection.h"
#include "Protocol.pb.h"

void TcpConnection::setFd(int f)
{
	fd_ = f;
}

TcpConnection::~TcpConnection()
{
	/*
	 * 善后操作：
	 *	1.关闭套接字
	 *	2.处理未发送的数据
	 */
	if(isWrite_ && writeBuffer_.hasData()){
		send();
	}
	close(fd_);
}

int TcpConnection::send()
{
	int tmp;
	while(1){
		tmp = ::send(fd_, writeBuffer_.data(), writeBuffer_.length(), MSG_NOSIGNAL);	
		if(tmp < 0){
			if(errno == EAGAIN){
				isWrite_ = false;
				return 0;
			}
			return -1;
		}
		writeBuffer_.update(tmp);
		if(!writeBuffer_.hasData()){
			return 0;
		}
	}
}

int TcpConnection::write(google::protobuf::Message*& msg)
{
	string strMsg;
	msg->SerializeToString(&strMsg);
	delete msg;
	char temp[10];
	sprintf(&temp[0], "%d", strMsg.size());
	writeBuffer_.append(&temp[0], 8);
	writeBuffer_.append(strMsg.c_str(), strMsg.size());

	if(isWrite_){
		return send();		
	}	
	return 0;
}

int TcpConnection::OnError()
{
	/*
	 * 打印错误日志
	 */
	return 0;
}

int TcpConnection::OnRead(vector<google::protobuf::Message*> &retVec)
{
	/*
	 * 接受数据，并将数据转换成具体的处理事件
	 */
	int flag = 1;
	int buflen;
	char buf[MAXREADBUFFER];
	while(flag){
	    buflen = recv(fd_, buf, MAXREADBUFFER, 0);
		if(buflen < 0){
			if(errno == EAGAIN || errno == EINTR){
				break;
			}else{
				return -1;
			}
		}else if(buflen == 0){
			return -1;//关闭socket,如果有剩余数据，先使用抛弃策略
		}else{
			//读取完毕,开始批量生成事件，将剩余数据放到缓冲区里面
			//1.先从readBuffer_中读取剩余数据
			//2.然后将剩余数据和新的数据开始进行生成
			//	1.先读取第一层协议
			//	2.根据第一层协议构造事件
			//	3.将事件插入数据中
			//3.将剩余数据放入readBuffer_
			//！！！！！！！！！！！！！注册ID号码到这里来
			readBuffer_.append(buf, buflen);	
			char temp[10];
			int iHeadProtoSize = 0;
			while(readBuffer_.length() > 8){
				memcpy(&temp[0], readBuffer_.data(), 8);
				iHeadProtoSize = atoi(temp);
				if(readBuffer_.length() < iHeadProtoSize)
				  break;
				readBuffer_.update(8);
				HeadProtocol* headProtocol = new HeadProtocol();
				headProtocol->ParseFromArray(readBuffer_.data(), iHeadProtoSize);
				epoll_->SetSourceID(fd_, headProtocol->source_id());
				readBuffer_.update(iHeadProtoSize);
				retVec.push_back(headProtocol);		
			}
		}
		if(buflen == MAXREADBUFFER){
			flag = 1;
		}else{
			flag = 0;
		}
	}
	return 0;
}
int TcpConnection::OnWrite()
{
	//将缓冲区的数据写入，同时设置状态
	isWrite_ = true;
	
	return send();
}

int TcpConnection::Fd()
{
	return fd_;
}

void TcpConnection::SetNonBlock()
{
	int opts;
    opts=fcntl(fd_,F_GETFL);
    if(opts<0)
    {
        //perror("fcntl(sock,GETFL)");
		assert(false);
    }
    opts = opts|O_NONBLOCK;
    if(fcntl(fd_,F_SETFL,opts)<0)
    {
        //perror("fcntl(sock,SETFL,opts)");
		assert(false);
    }

}

void TcpConnection::SetIpPort(const string& ip, const string& port)
{
	ip_ = ip;
	port_ = atoi(port.c_str());
}

bool TcpConnection::openServer()
{
	struct sockaddr_in serveraddr;
	fd_ = socket(AF_INET, SOCK_STREAM, 0);
	if(fd_ < 0){
		cout << "Socket create failed" << endl;
		return false;
	}
	SetNonBlock();
	bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
	//inet_aton(ip_.c_str(),&(serveraddr.sin_addr));//htons(portnumber);
	serveraddr.sin_addr.s_addr = htons(INADDR_ANY);
	serveraddr.sin_port=htons(port_);
	if(0 > bind(fd_,(sockaddr *)&serveraddr, sizeof(serveraddr))){
		cout << "Socket bind failed:" << errno << endl;
		return false;
	};
    if(0 > listen(fd_, LISTENQ)){
		cout << "Socket listen failed" << endl;
		return false;
	};

	open_ = true;
	return true;				
}
