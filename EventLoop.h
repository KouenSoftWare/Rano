#pragma once

#include <string>
#include <vector>
#include <map>
#include <boost/smart_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/function.hpp>
#include <boost/utility.hpp>
#include <sys/syscall.h>
#include <unistd.h>

#include "AutoMutex.h"

using namespace std;


class Event;
class EventSourceBase;
class ProtocolFactory;

class EventFunc;
class EventLoop;

typedef boost::function<void(boost::shared_ptr<Event>, boost::weak_ptr<EventLoop>)> FuncPtr;

class EventFunc
{
	FuncPtr func_;
	boost::shared_ptr<Event> event_;
	boost::weak_ptr<EventLoop> el_;
public:
	EventFunc(FuncPtr func, boost::shared_ptr<Event> event, boost::weak_ptr<EventLoop> el):
		func_(func),
		event_(event),
		el_(el)
	{}

	void doWork(){
		func_(event_, el_);
	}

	EventFunc& operator=(const EventFunc& rhs){
		if(&rhs != this){
			event_ = rhs.event_;	
			func_  = rhs.func_;
		}
		return *this;
	}
};

class EventLoop: 
	public boost::enable_shared_from_this<EventLoop>,
	public boost::noncopyable
{
public:
	EventLoop();
	~EventLoop();

	static EventLoop* getEventLoopOfCurrentThread();

	//确认是否是在本地线程
	void AssertInLoopThread(){
		if (!isInLoopThread()){
			AbortNotInLoopThread();
		}
	}

	//返回：调用ID是否等于EventLoop的创建ID
	bool isInLoopThread() const {
		return threadID_ == getpid();
	}
	
	//通过更改标记位来退出事件循环
	void Quit(){
		looping_ = false;	
	}

	//其他线程调用的时候，将数据添加到队列
	void RunInLoop(FuncPtr func, boost::shared_ptr<Event> eventPtr){
		EventFunc ef(func, eventPtr, boost::weak_ptr<EventLoop>(shared_from_this()));
		AutoMutex m(mutex_);		
		taskArray_.push_back(ef);
	}

	void reg(string eventName, boost::shared_ptr<Event> eventPtr, FuncPtr func){
		map<string, EventFunc>::iterator iter = eventFuncPtr_.find(eventName);		
		{
			EventFunc ef(func, eventPtr, boost::weak_ptr<EventLoop>(shared_from_this()));
			AutoMutex m(mutex_);		
			if (iter == eventFuncPtr_.end()){
				eventFuncPtr_.insert(pair<string, EventFunc>(eventName, ef));
			}else{
				iter->second = ef;
			}
		}
	}
	
	void reg(string protocolName, boost::shared_ptr<ProtocolFactory> factory){
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

	void reg(boost::shared_ptr<EventSourceBase> source){
		AutoMutex m(mutex_);
		eventSources_.push_back(source);
	}

	void loop();
private:
	CMutex mutex_;
	bool looping_;
	const pid_t threadID_;
	vector<EventFunc>	taskArray_;
	vector<boost::shared_ptr<EventSourceBase> > eventSources_;
	map<string, EventFunc> eventFuncPtr_;
	map<string, boost::shared_ptr<ProtocolFactory> > protocolFactorys_;

private:
	//退出循环
	void AbortNotInLoopThread();

	//插入其他队列的任务到本地中你
	void DoOtherThreadWork();
};
