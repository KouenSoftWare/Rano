#include <iostream>
#include <boost/bind.hpp>
#include "Epoll.h"
#include "EventLoop.h"
#include "EventFactory.h"
#include "Event.h"
#include "ServerTcpEvent.h"
#include <string.h>

struct echoEvent:public Event
{
	char msg[32];
};

void echo(boost::shared_ptr<Event>& event, boost::weak_ptr<EventLoop>& el)
{
	assert(0==strcmp(event->getName(),"echoEvent"));
	echoEvent* e = (echoEvent*)event.get();
//	cout << "\tSourceID " << e->l1.sourceID << "Say: " << e->msg << endl;
	ServerTcpEvent *pServerTcp = new ServerTcpEvent();
	pServerTcp->l1.set("$#@!", sizeof(echoEvent), -1, e->l1.sourceID, 0, 0, e->l1.serialNumber, "echoEvent");
	/*
	strcpy(pServerTcp->l1.featureCode, "$#@!");
	strcpy(pServerTcp->l1.level2Name, "echoEvent");
	pServerTcp->l1.jumpCount = 0;
	pServerTcp->l1.level2Size = sizeof(echoEvent);
	pServerTcp->l1.missCount = 0;
	pServerTcp->l1.sourceID = 1;
	pServerTcp->l1.targetID = 0;
	pServerTcp->l1.serialNumber = e->l1.serialNumber;
	*/
	vector<char> temp; temp.resize(sizeof(echoEvent));
	memcpy(&temp[0], e, sizeof(echoEvent));
	pServerTcp->setBuf(temp);
	boost::shared_ptr<Event> pE(pServerTcp);
	boost::shared_ptr<EventLoop> pEL = el.lock();
	pEL->SendEvents("Epoll", pE);
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
	el.reg("Epoll", target);

	el.reg("echoEvent", f);
	el.reg("echoEvent", boost::bind(&echo, _1, _2));
	el.reg(source);
	el.loop();	
	return 0;
}
