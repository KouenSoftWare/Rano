#include "EventLoop.h"
#include "EventSourceBase.h"

EventSourceBase::EventSourceBase():
	loop_(EventLoop::getEventLoopOfCurrentThread())
{
	;	
}

EventSourceBase::~EventSourceBase()
{
	;
}

void EventSourceBase::init()
{
	;
}

void EventSourceBase::GetEvents(vector<boost::shared_ptr<Event> >& ret)
{
	;
}
