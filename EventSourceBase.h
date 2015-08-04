#pragma once

#include <boost/shared_ptr.hpp>
#include <vector>

using namespace std;

class EventLoop;
class EventFunc;

class EventSourceBase
{	
protected:
	shared_ptr<EventLoop> loop_;
public:
	EventSourceBase();
	
	virtual ~EventSourceBase(){};
	virtual void init(){};
	virtual	void GetEvents(vector<boost::shared_ptr<EventFunc> >&);
};
