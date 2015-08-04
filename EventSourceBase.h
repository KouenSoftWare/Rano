#pragma once

#include <boost/shared_ptr.hpp>
#include <vector>

using namespace std;

class EventLoop;
class Event;

class EventSourceBase
{	
protected:
	boost::shared_ptr<EventLoop> loop_;
public:
	EventSourceBase();
	
	virtual ~EventSourceBase();
	virtual void init();
	virtual	void GetEvents(vector<boost::shared_ptr<Event> >&);
};
