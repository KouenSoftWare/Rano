#pragma once

#include "LockQueue.h"
#include <pthread.h>
#include <map>
#include <vector>
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/function.hpp>

using namespace std;

class Event;
class EventLoop;

typedef boost::function<void(boost::shared_ptr<Event>&, boost::weak_ptr<EventLoop>&)> FuncPtr;

class ThreadPool{
	LockQueue<boost::shared_ptr<EventFunc> > queue_;
	map<string, EventFunc> eventExecuteList_;
	boost::weak_ptr<EventLoop> el_;
	vector<boost::shared_ptr<pthread_t> > threadGroup_;
public:
	ThreadPool(boost::weak_ptr<EventLoop>);
	void reg(string& name, FuncPtr f);
	bool push(boost::shared_ptr<Event>& event);

};
