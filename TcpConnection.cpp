#include "TcpConnection.h"

TcpConnection::~TcpConnection()
{
	/*
	 * 善后操作：
	 *	1.关闭套接字
	 *	2.处理未发送的数据
	 */
	if(isWrite_ && bufferSpace_){
		OnWrite();
	}
	close(fd_);
}

int TcpConnection::write(string& msg)
{
	return 0;	
}

int TcpConnection::OnError()
{
	/*
	 * 打印错误日志
	 */
	return 0;
}

int TcpConnection::OnRead(vector<boost::shared_ptr<Event> > &ret_vecEF)
{
	/*
	 * 接受数据，并将数据转换成具体的处理事件
	 */
	return 0;
}
int TcpConnection::OnWrite()
{
	return 0;
}

int TcpConnection::Fd()
{
	return fd_;
}

void TcpConnection::SetNonBlock(){}
void TcpConnection::SetIpPort(const string& ip, const string& port){}
bool TcpConnection::openServer()
{
	return false;
}
