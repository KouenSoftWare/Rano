#include "EventLoop.h"
#include <iostream>

using namespace std;

__thread EventLoop* t_loopInThisThread = NULL;

EventLoop* EventLoop::getEventLoopOfCurrentThread()
{
	return t_loopInThisThread;
}

EventLoop::EventLoop():
	looping_(false),
	threadID_(getpid())
{
	if(t_loopInThisThread){
		cout << "Another EventLoop " << t_loopInThisThread
			 << " exists in this thread " << threadID_ << endl;
	}else{
		t_loopInThisThread = this;
	}
}

EventLoop::~EventLoop()
{
	assert(!looping_);
	t_loopInThisThread = NULL;
}

void EventLoop::DoOtherThreadWork()
{
	vector<EventFunc> work;
	{
		AutoMutex m(mutex_);
		taskArray_.swap(work);
	}

	vector<EventFunc>::iterator beg = work.begin(), end = work.end();
	while(beg != end){
		beg->doWork();
		beg++;
	}
}


void EventLoop::AbortNotInLoopThread()
{
	cout << "请别在其他线程运行Eventloop!" << endl;;//打印错误信息
}

void EventLoop::loop()
{
	assert(!looping_);
	AssertInLoopThread();
	looping_ = true;

	vector<boost::shared_ptr<EventFunc> > eventArray;
	while(looping_){
		eventArray.clear();
		for(size_t i = 0; i != eventSources_.size(); i++){
			//eventSources_[i]->GetEvents(eventArray);
		}	
		for(size_t i = 0; i != eventArray.size(); i++){
			eventArray[i]->doWork();
		}
	}
}
