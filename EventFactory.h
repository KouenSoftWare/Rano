#pragma once

#include "Event.h"

class EventFactory{
public:
	virtual Event* create()=0;
	Event* GetEvent(char*,  int);
};
