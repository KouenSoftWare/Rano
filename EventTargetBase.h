#pragma once

#include <boost/shared_ptr.hpp>
#include <vector>

using namespace std;

class EventLoop;
class Event;

class EventTargetBase
{	
protected:
	boost::shared_ptr<EventLoop> loop_;
public:
	EventTargetBase();
	
	virtual ~EventTargetBase();
	virtual	int SendEvents(boost::shared_ptr<Event> &);
};
