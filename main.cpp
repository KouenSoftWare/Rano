#include <iostream>
#include <boost/bind.hpp>
#include "Epoll.h"
#include "EventLoop.h"
#include "EventFactory.h"
#include "ServerTcpEvent.h"
#include "ThreadPool.h"
#include <string.h>

struct echoEvent:public Event
{
	char msg[32];
};

int echo(Event*& event, ThreadPool *pool)
{
	assert(0==strcmp(event->getName(),"echoEvent"));
	echoEvent* e = (echoEvent*)event;
	ServerTcpEvent *pServerTcp = pool->GetIOEvent();
	assert(pServerTcp != NULL);
	pServerTcp->l1.set("$#@!", sizeof(echoEvent), -1, e->l1.sourceID, 0, 0, e->l1.serialNumber, "echoEvent");
	pServerTcp->setName("Epoll");
	vector<char> temp; temp.resize(sizeof(echoEvent));
	memcpy(&temp[0], e, sizeof(echoEvent));
	pServerTcp->setBuf(temp);
	pool->push(OUT, pServerTcp);
	pool->SaveEvent(event->getName(), event);
	return 0;
}

class echoFactory:
	public EventFactory
{
public:
	Event* create(){
		echoEvent* p = new echoEvent();		
		return p;
	}
};

int main()
{
	EventLoop el;
	Epoll *epoll = new Epoll;
	boost::shared_ptr<EventSourceBase> source(epoll);	
	boost::shared_ptr<EventTargetBase> target(epoll);	
	boost::shared_ptr<EventFactory> f(new echoFactory);	
	el.reg("TcpRecvEvent", boost::bind(&TcpRecvEventToOtherEvent, _1 ,_2));
	el.reg("echoEvent", boost::bind(&echo, _1, _2));
	el.reg("Epoll", target);
	el.reg("echoEvent", f);
	el.reg(source);

	el.loop();	
	return 0;
}
