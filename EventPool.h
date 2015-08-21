#pragma once

#include "EventFactory.h"
#include "AutoMutex.h"
#include <queue>

class EventPool
{
private:
	//string=Event Name
	map<string, queue<Event*> > ep_;
	map<string, boost::shared_ptr<EventFactory> > eventFactory_;
	int defaultCount_;
	CMutex mutex_;
public:
	EventPool(int number = 100);

	Event* GetSpaceEvent(string);
	void SaveEvent(string name, Event*);

	void InitEventPool(string, boost::shared_ptr<EventFactory>&);
};
