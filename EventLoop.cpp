#include "EventLoop.h"
#include "Event.h"
#include "EventTargetBase.h"
#include "EventSourceBase.h"
#include <iostream>

using namespace std;

EventLoop::EventLoop():
	qIn_(12800),
	qOut_(12800),
	qError_(12800),
	threadPool_(5, qIn_, qOut_, qError_),
	mutex_(),
	looping_(false)
{
}

EventLoop::~EventLoop()
{
	assert(!looping_);
}

void EventLoop::loop()
{
	assert(!looping_);
	looping_ = true;

	vector<Event*> eventArray;
	Event* event;
	threadPool_.start();
	while(looping_){
		eventArray.clear();
		for(size_t i = 0; i != eventSources_.size(); i++){
			eventSources_[i]->GetEvents(eventArray);
		}	
		for(size_t i = 0; i < eventArray.size(); i++){
			while(!qIn_.push(eventArray[i]));	
		}
		map<string, boost::shared_ptr<EventTargetBase> >::iterator iter = eventTarget_.begin();
		while(qOut_.pop(event)){
			if(iter == eventTarget_.end() || iter->first != event->getName()){
				iter = eventTarget_.find(event->getName());
				if (iter == eventTarget_.end()){
					while(!qError_.push(event));
				}
			}else{
				iter->second->SendEvents(event);
			}
		}
	}
	threadPool_.shutdown();
}

