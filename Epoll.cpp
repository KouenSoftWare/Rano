#include "Epoll.h"
#include <signal.h>

using namespace std;


Epoll::Epoll():
	server_(this, &ioPool_)
{
	signal(SIGPIPE, SIG_IGN);
	epfd_ =	epoll_create(MAXEVENTS);
	string ip("127.0.0.1"), port("7392");
	server_.SetIpPort(ip, port);
	assert(server_.openServer());
	struct epoll_event event;
	event.data.fd = server_.Fd();
	event.events = EPOLLIN | EPOLLET;
	if(-1 == epoll_ctl(epfd_ , EPOLL_CTL_ADD, server_.Fd(), &event)){
		cout << "服务器句柄不能被添加到监听队列中:" << errno << endl;
	}
}

int Epoll::DelListen(const int& fd, map<int, boost::shared_ptr<TcpConnection> >::iterator& iter)
{
	struct epoll_event event;
	event.data.fd = fd;
	event.events = EPOLLIN | EPOLLET | EPOLLOUT;
	if(-1 == epoll_ctl (epfd_, EPOLL_CTL_DEL, fd, &event)){
		cout << "<!>删除监听错误<!>  句柄:" << fd << endl;
		return -1;
	}else{
		listen_list_.erase(iter);
//		cout << "\t删除监听成功" << endl;
		return 0;
	}
}

void Epoll::GetEvents(vector<Event*>&ret_eventArray)
{
	struct epoll_event event;
	int n = epoll_wait(epfd_, waitEP_, MAXEVENTS, 1);
	for(int i=0; i<n; i++){
		if ((waitEP_[i].events & EPOLLERR) || (waitEP_[i].events & EPOLLHUP)){
			map<int, boost::shared_ptr<TcpConnection> >::iterator iter = listen_list_.find(waitEP_[i].data.fd);
			assert(iter != listen_list_.end());
			iter->second->OnError();
//			cout << "\t<!>各种断开错误事件触发<!> errno:" << errno << " Events:" << waitEP_[i].events << endl;
			DelListen(iter->second->Fd(), iter);
		}else if(server_.Fd() == waitEP_[i].data.fd){
			while(1){
				sockaddr in_addr;
				socklen_t in_len = sizeof(struct sockaddr);
				int clientFd = accept(server_.Fd(), &in_addr, &in_len);
				if(clientFd == -1){
//					cout << "Accept Error:" << errno << endl;
					//错误的接受或者已经没有客户端连接
					break;
				}
				char hbuf[NI_MAXHOST], sbuf[NI_MAXSERV];
				assert(0 == getnameinfo (&in_addr, in_len, hbuf, sizeof(hbuf), sbuf, sizeof(sbuf), NI_NUMERICHOST | NI_NUMERICSERV));
				boost::shared_ptr<TcpConnection> pTcp(new TcpConnection(this, &ioPool_));
				pTcp->SetIpPort(hbuf, sbuf);
				pTcp->setFd(clientFd);
				event.data.fd = clientFd;
				event.events = EPOLLIN | EPOLLET | EPOLLOUT;
				if(-1 == epoll_ctl (epfd_, EPOLL_CTL_ADD, clientFd, &event)){
					cout << "<!>添加监听错误<!>"<< endl;
				}else{
//					cout << "添加监听成功" << endl;
					listen_list_.insert(pair<int, boost::shared_ptr<TcpConnection> >(clientFd ,pTcp));
				}
			}
		}else{
			if(waitEP_[i].events & EPOLLIN){
				//触发可读事件
				//1 寻找TcpConnection对象
				//2 使用对象读取内容，并转换为想对应的event对象
				//3 将剩余接受的内容放到容器中，直到没有数据位置
				//4 将所有构建好的Event传到这里
				//5 将东西传递到EventLoop
				map<int, boost::shared_ptr<TcpConnection> >::iterator iter = listen_list_.find(waitEP_[i].data.fd);
				if(iter != listen_list_.end()){
					if(iter->second->OnRead(ret_eventArray) < 0){
						//cout << "\t<!>错误的可读事件<!>";
						DelListen(iter->second->Fd(), iter);
					}
				}
			}
			if(waitEP_[i].events & EPOLLOUT){
				//触发可写事件
				map<int, boost::shared_ptr<TcpConnection> >::iterator iter = listen_list_.find(waitEP_[i].data.fd);
				if(iter != listen_list_.end()){
					if(iter->second->OnWrite() < 0){
						//cout << "\t<!>错误的可写事件<!>";
						DelListen(iter->second->Fd(), iter);
					}
				}
			}
		}	
	}
}

void Epoll::SetSourceID(int fd, int sId)
{
	map<int, int>::iterator iter = mapSourceID_.find(sId);
	if(iter == mapSourceID_.end()){
		mapSourceID_.insert(pair<int, int>(sId, fd));	
	}else{
		iter->second = fd;
	}
}

int Epoll::SendEvents(Event* &event)
{
	int fd;	//获取Event的fd，强制将其转换成对应的TCP事件，就行.这种属于框架的内部事件	
	map<int, int>::iterator iterSouceId = mapSourceID_.find(event->l1.targetID);
	if(iterSouceId == mapSourceID_.end()){
		SaveEvent(event); 	
	//	cout << "<!>Not Find SourceID<!>" << endl;
		return -1;
	}
	fd = iterSouceId->second;
	map<int, boost::shared_ptr<TcpConnection> >::iterator iter = listen_list_.find(fd);
	if(iter == listen_list_.end()){
		SaveEvent(event); 	
	//	cout << "<!>Not Find TcpConnection<!>" << endl;
		return -1;
	}
	return iter->second->write(event);
}

void Epoll::SaveEvent(Event* &event)
{
	map<int, vector<Event*> >::iterator iter = mapSourceIDToSaveEvents_.find(event->l1.targetID);
	if(iter == mapSourceIDToSaveEvents_.end()){
		vector<Event*> vec;
		vec.push_back(event);
		mapSourceIDToSaveEvents_.insert(pair<int, vector<Event*> >(event->l1.targetID, vec));
	}else{
		iter->second.push_back(event);
	}
}

void Epoll::LoadEvents(int sId, vector<Event*> &vecEvent)
{
	map<int, vector<Event*> >::iterator iter = mapSourceIDToSaveEvents_.find(sId);
	if(iter != mapSourceIDToSaveEvents_.end()){
		vecEvent.swap(iter->second);
	}
}
