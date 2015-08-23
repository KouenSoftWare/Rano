#pragma once

#include "Event.h"
#include "EventPool.h"
#include "ServerTcpEvent.h"
#include "AutoMutex.h"

#define IN 0
#define OUT 1
#define ERROR 2

class ThreadPool
{
private:
	int threadCount_;
	bool looping_;

	boost::lockfree::queue<Event*, boost::lockfree::fixed_sized<false> > &qIn_;
	boost::lockfree::queue<Event*, boost::lockfree::fixed_sized<false> > &qOut_;
	boost::lockfree::queue<Event*, boost::lockfree::fixed_sized<false> > &qError_;

	EventPool eventPool_;

	CMutex mutex_;

	vector<boost::thread*> vecpThrd_;
	map<string, FuncPtr> eventFunctionList_;
	map<string, boost::shared_ptr<EventFactory> > eventFactory_;
public:
	ThreadPool(int threadCount,
			   boost::lockfree::queue<Event*, boost::lockfree::fixed_sized<false> > &qIn,
			   boost::lockfree::queue<Event*, boost::lockfree::fixed_sized<false> > &qOut,
			   boost::lockfree::queue<Event*, boost::lockfree::fixed_sized<false> > &qError):
		threadCount_(threadCount),
		looping_(true),
		qIn_(qIn),
		qOut_(qOut),
		qError_(qError)
	{
	}

	void start(){
		boost::function<void()> f = boost::bind(&ThreadPool::Run, this);
		for (int i = 0; i < threadCount_; i++){
			boost::thread* thrd = new boost::thread(f);
			vecpThrd_.push_back(thrd);
		}
	}

	void reg(string name, FuncPtr f){
		eventFunctionList_.insert(pair<string, FuncPtr>(name, f));
	}

	boost::shared_ptr<EventFactory> getFactroy(string name){
		return eventFactory_.find(name)->second;
	}

	void reg(string name, boost::shared_ptr<EventFactory>& factory){
		eventFactory_.insert(pair<string, boost::shared_ptr<EventFactory> >(name, factory));
		eventPool_.InitEventPool(name, factory);
	}

	~ThreadPool(){
		for (int i = 0; i < threadCount_; i++){
			vecpThrd_[i]->join();
		}
	}


	Event* GetEvent(string name);

	void SaveEvent(string name, Event* p);

	void shutdown(){
		looping_ = false;
	}

	void push(int Option, Event *e);

	void Run();
};
