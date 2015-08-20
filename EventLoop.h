#pragma once

#include "AutoMutex.h"
#include "EventFunc.h"
#include "ThreadPool.h"

class EventLoop: 
	public boost::noncopyable
{
private:
	boost::lockfree::queue<Event*, boost::lockfree::fixed_sized<false> > qIn_;
	boost::lockfree::queue<Event*, boost::lockfree::fixed_sized<false> > qOut_;
	boost::lockfree::queue<Event*, boost::lockfree::fixed_sized<false> > qError_;
	ThreadPool threadPool_;
	CMutex mutex_;
	bool looping_;
	vector<boost::shared_ptr<EventSourceBase> > eventSources_;
	map<string, boost::shared_ptr<EventTargetBase> > eventTarget_;
	map<string, boost::shared_ptr<ProtocolFactory> > protocolFactorys_;
public:
	EventLoop();
	~EventLoop();

	
	//通过更改标记位来退出事件循环
	void Quit(){
		looping_ = false;	
	}

	void reg(string eventName, FuncPtr func){
		AutoMutex m(mutex_);
		threadPool_.reg(eventName, func);		
	}

	void reg(string protocolName, boost::shared_ptr<ProtocolFactory>& factory){
		map<string, boost::shared_ptr<ProtocolFactory> >::iterator iter = protocolFactorys_.find(protocolName);		
		{
			AutoMutex m(mutex_);		
			if (iter == protocolFactorys_.end()){
				protocolFactorys_.insert(pair<string, boost::shared_ptr<ProtocolFactory> >(protocolName, factory));
			}else{
				protocolFactorys_[protocolName] = factory;
			}
		}
	}

	void reg(boost::shared_ptr<EventSourceBase>& source){
		AutoMutex m(mutex_);
		eventSources_.push_back(source);
	}

	void reg(string name, boost::shared_ptr<EventTargetBase>& target){
		AutoMutex m(mutex_);
		eventTarget_.insert(pair<string, boost::shared_ptr<EventTargetBase> >(name, target));
	}

	void reg(string name, boost::shared_ptr<EventFactory>& factory){
		AutoMutex m(mutex_);
		threadPool_.reg(name, factory);
	}

	void loop();

};
