#include "EventLoop.h"
#include "EventSourceBase.h"

EventSourceBase::EventSourceBase():
	loop_(getEventLoopOfCurrentThread())
{
	
}
