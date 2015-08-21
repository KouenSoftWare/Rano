#pragma once

#include "Event.h"

class EventFunc
{
	FuncPtr func_;
	Event* event_;
	ThreadPool* pool_;
public:
	EventFunc(FuncPtr func, Event*& event, ThreadPool* tp):
		func_(func),
		event_(event),
		pool_(tp)
	{}

	void doWork(){
		func_(event_, pool_);
	}
};


