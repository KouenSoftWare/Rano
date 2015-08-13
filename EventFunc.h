#pragma once
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/function.hpp>
class Event;
class EventLoop;

typedef boost::function<void(boost::shared_ptr<Event>&, boost::weak_ptr<EventLoop>&)> FuncPtr;

class EventFunc
{
	FuncPtr func_;
	boost::shared_ptr<Event> event_;
	boost::weak_ptr<EventLoop> el_;
public:
	EventFunc(FuncPtr func, boost::shared_ptr<Event>& event, boost::weak_ptr<EventLoop> el);
	EventFunc(FuncPtr func,  boost::weak_ptr<EventLoop> el);
	void setEvent(boost::shared_ptr<Event> &e);
	void doWork();

	EventFunc& operator=(const EventFunc& rhs);
};
