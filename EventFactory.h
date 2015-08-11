#pragma once

#include <boost/shared_ptr.hpp>

class Event;
class EventFactory{
public:
	virtual boost::shared_ptr<Event> create()=0;
	boost::shared_ptr<Event> GetEvent(char*,  int);
};
