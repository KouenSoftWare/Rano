#include <iostream>
#include <boost/bind.hpp>
#include "Epoll.h"
#include "EventLoop.h"
#include "ServerTcpEvent.h"
#include "ThreadPool.h"
#include <string.h>

int main()
{
	EventLoop el;
	Epoll *epoll = new Epoll;
	boost::shared_ptr<EventSourceBase> source(epoll);	
	boost::shared_ptr<EventTargetBase> target(epoll);	
	el.reg("Epoll", target);
	el.reg(source);

	el.loop();	
	return 0;
}
