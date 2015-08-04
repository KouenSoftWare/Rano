#include <iostream>
#include <boost/bind.hpp>
#include "Epoll.h"
#include "EventLoop.h"
#include "EventFactory.h"
#include "Event.h"
#include <string.h>

struct echoEvent:public Event
{
	char msg[32];
};

void echo(boost::shared_ptr<Event>& event, boost::weak_ptr<EventLoop>& el)
{
	assert(0==strcmp(event->getName(),"echoEvent"));
	echoEvent* e = (echoEvent*)event.get();
	cout << e->msg << endl;
}

class echoFactory:
	public EventFactory
{
public:
	boost::shared_ptr<Event> create(){
		echoEvent* p = new echoEvent();		
		boost::shared_ptr<Event> ret(p);
		return ret;
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
	el.reg("echoFactory", f);
	el.reg(source);
	el.reg("Epoll", target);
	el.reg("echoEvent", boost::bind(&echo, _1, _2));
	el.loop();	
	return 0;
}
