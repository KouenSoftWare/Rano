#include "Epoll.h"
#include "EventLoop.h"
#include <assert.h>

Epoll::Epoll()
{
	struct epoll_event event;
	epfd_ =	epoll_create(0);
	//加入对服务器的监听 server_
}

Epoll::GetEvents(vector<boost::shared_ptr<EventFunc> > &ret_eventArray)
{
	struct epoll_event event;
	int n = epoll_wait(epfd_, &waitEP_, MAXEVENTS, -1);
	for(int i=0; i!=n; i++){
		if ((events[i].events & EPOLLERR) || (events[i].events & EPOLLHUP) || (!(events[i].events & EPOLLIN))){
			map<int, boost::shared_ptr<TcpConnection> >::iterator iter = listen_list_[events[i].data.fd];
			assert(iter != listen_list_.end());
			iter->second->OnError();
			listen_list_.erase(iter);
		}else if(server_.fd() == events[i].data.fd){
			//添加新的客户端连接到监听队列
			while(1){
				sockaddr in_addr;
				socklen_t in_len;
				int clientFd = accept(server_.fd(), &in_addr, &in_len);
				if(clientFd == -1){
					//错误的接受或者已经没有客户端连接
					break;
				}
				event.data.fd = infd;
				event.events = EPOLLIN | EPOLLET;
				if(-1 == epoll_ctl (efd, EPOLL_CTL_ADD, infd, &event)){
					;//添加监听错误
				}
			}
		}else{
			if(events[i].events & EPOLLIN){
				//触发可读事件
				//1 寻找TcpConnection对象
				//2 使用对象读取内容，并转换为想对应的event对象
				//3 将剩余接受的内容放到容器中，直到没有数据位置
				//4 将所有构建好的Event传到这里
				//5 将东西传递到EventLoop
			}
			if(events[i].events & EPOLLOUT){
				//触发可写事件
			}
		}	
	}
}
