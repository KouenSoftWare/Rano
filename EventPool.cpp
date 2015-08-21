#include "EventPool.h"
EventPool::EventPool(int number)
{
	defaultCount_ = number;
}

Event* EventPool::GetSpaceEvent(string name);

void EventPool::SaveEvent(Event* pE);

void EventPool::InitEventPool(string name, boost::shared_ptr<EventFactory>& factory);
