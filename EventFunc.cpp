#include "EventFunc.h"
#include "EventLoop.h"
EventFunc::EventFunc(FuncPtr func, boost::shared_ptr<Event>& event, boost::weak_ptr<EventLoop> el):
		func_(func),
		event_(event),
		el_(el){}

EventFunc::EventFunc(FuncPtr func,  boost::weak_ptr<EventLoop> el):
		func_(func),
		event_(),
		el_(el){}

EventFunc::EventFunc():
		func_(),
		event_(),
		el_(){}

EventFunc::EventFunc(const EventFunc& rhs)
{
	event_ = rhs.event_;
	el_ = rhs.el_;
	func_ = rhs.func_;
}
		
void EventFunc::setEvent(boost::shared_ptr<Event> &e){
	event_.swap(e);
}

void EventFunc::doWork(){
	func_(event_, el_);
	event_.reset();
}

EventFunc& EventFunc::operator=(const EventFunc& rhs){
	if(&rhs != this){
		event_ = rhs.event_;	
		func_  = rhs.func_;
		el_ = rhs.el_;
	}
	return *this;
}
