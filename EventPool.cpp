#include "EventPool.h"
EventPool::EventPool(int number)
{
	defaultCount_ = number;
}

Event* EventPool::GetSpaceEvent(string name)
{
//	AutoMutex l(mutex_);
	mutex_.lock();
	map<string, queue<Event*> >::iterator iter = ep_.find(name);
	if(iter == ep_.end()){
		mutex_.unlock();
		return NULL;
	}
	if(iter->second.empty()){
		cout << "EventPool too more Big: " << defaultCount_ << endl;
		map<string, boost::shared_ptr<EventFactory> >::iterator iterF = eventFactory_.find(name);
		for(int i = 0; i < defaultCount_; i++){
			Event* p = NULL;
			p = iterF->second->create();
			iter->second.push(p);
		}
		defaultCount_ *= 2;
	}

	Event* p = iter->second.front();
	iter->second.pop();
	mutex_.unlock();
	return p;
}

void EventPool::SaveEvent(string name, Event* pE)
{
	mutex_.lock();
	map<string, queue<Event*> >::iterator iter = ep_.find(name);
	assert(iter != ep_.end());
	iter->second.push(pE);
	mutex_.unlock();
}

void EventPool::InitEventPool(string name, boost::shared_ptr<EventFactory>& factory)
{
	queue<Event*> queueEvent;
	for(int i = 0; i < defaultCount_; i++){
		queueEvent.push(factory->create());
	}
	ep_.insert(pair<string, queue<Event*> >(name, queueEvent));
	eventFactory_.insert(pair<string, boost::shared_ptr<EventFactory> >(name, factory));
}
