#include "ThreadPool.h"
#include "Event.h"
#include "EventFunc.h"

void* Consumer(void* a)
{
	LockQueue<EventFunc>* queue = (LockQueue<EventFunc>* )a;
	EventFunc event;
	while(1){
		queue->wait_and_pop(event);
		//执行具体工作;
	}
	return NULL;
}

ThreadPool::ThreadPool(boost::weak_ptr<EventLoop> el):el_(el)
{
	for(int i=0; i<10; i++){
		boost::shared_ptr<pthread_t> p(new pthread_t);
		threadGroup_.push_back(p);
		pthread_create(p.get(), NULL, Consumer, &queue_);
	}	
}
void ThreadPool::reg(string& name, FuncPtr f)
{
	map<string, EventFunc>::iterator iter = eventExecuteList_.find(name);
	if(iter == eventExecuteList_.end()){
		EventFunc ef(f, el_);
		eventExecuteList_.insert(pair<string, EventFunc>(name, ef));
	}else{
		iter->second.setFunc(f);
	}
}

bool ThreadPool::push(boost::shared_ptr<Event>& event)
{
	map<string, EventFunc>::iterator iter = eventExecuteList_.find(event->getName());
	if(iter == eventExecuteList_.end())
		return false;
	iter->second.setEvent(event);
	queue_.push(iter->second);
	return true;
}
