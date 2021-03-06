#pragma once

#include "Event.h"

class EventSourceBase
{	
public:
	EventSourceBase();
	
	virtual ~EventSourceBase();
	virtual void init();
	virtual	void GetEvents(vector<Event*>&);
};
