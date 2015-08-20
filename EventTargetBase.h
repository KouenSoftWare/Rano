#pragma once

#include "Event.h"

class EventTargetBase
{	
public:
	EventTargetBase();
	
	virtual ~EventTargetBase();
	virtual	int SendEvents(Event* &);
};
