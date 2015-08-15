#pragma once

#include <boost/lockfree/queue.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>

#define IN 1
#define OUT 2
#define ERROR 3

class Event;

class ThreadPool
{
private:
	boost::lockfree::queue<boost::shared_ptr<Event> > (&queues_)[3];
	int threadCount_;
	bool looping_;

	vector<boost::thread*> vecpThrd_;
public:
	ThreadPool(int threadCount, boost::lockfree::queue<boost::shared_ptr<Event> > (&queues)[3]):
		queues_(queues),
		threadCount_(threadCount),
		looping_(true){
		boost::function0<void> f = boost::bind(&ThreadPool::Run, this);
		for (int i = 0; i < threadCount_; i++){
			boost::thread* thrd = new boost::thread(f);
			vecpThrd_.push_back(thrd);
		}
	}
	~ThreadPool(){
		for (int i = 0; i < threadCount_; i++){
			vecpThrd_[i]->join();
		}
	}

	void shutdown(){
		looping_ = false;
	}

	void Run();

};
