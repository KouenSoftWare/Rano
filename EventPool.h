#pragma once

#include "EventFactory.h"

class EventPool
{
private:
	//string=Event Name
	map<string, queue<Event*> > ep_;
	map<string, boost::shared_ptr<EventFactory> > eventFactory_;
	int defaultCount_;
public:
	EventPool(int number = 512);

	Event* GetSpaceEvent(string)
	void SaveEvent(Event*);

	void InitEventPool(string, boost::shared_ptr<EventFactory>&);
};
