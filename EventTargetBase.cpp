#include "EventLoop.h"
#include "EventTargetBase.h"

EventTargetBase::EventTargetBase():
	loop_(EventLoop::getEventLoopOfCurrentThread())
{
	;	
}

EventTargetBase::~EventTargetBase()
{
	;
}


int EventTargetBase::SendEvents(boost::shared_ptr<Event>& ret)
{
	return 0;
}
