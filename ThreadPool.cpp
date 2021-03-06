#include "ThreadPool.h"
#include "EventFunc.h"

//生成EventFunc对象	
//执行EventFunc对象
//将三个队列作为参数传递到里面，重新修改FuncPtr的参数为void (boost::shared_ptr<Event>&, boost::lockfree::queue<boost::shared_ptr<Event> > (&)[3])
/*
 * 在EventLoop中修改：
 *		1.首先将所有事件都插入到queues[IN]，然后从queues[OUT]读取需要发送的事件，从queues[ERROR]中读取没有对应执行函数的事件
 *		2.所有到queues[OUT]都是IO事件，其中需要包含几个信息：
 *			1.发送内容
 *			2.发送的句柄
 *		3.将EventFunc移植出去
 *		4.将所有FuncPtr参数进行修改，并且修改对应的处理函数
*/
void ThreadPool::Run()
{
	Event* event;
	while(looping_){
		while(qIn_.pop(event)){
			map<string, FuncPtr>::iterator iter = eventFunctionList_.find(event->getName());
			if(iter == eventFunctionList_.end()){
			    assert(false);
				while(!qError_.push(event));
				continue;
			}
			EventFunc ef(iter->second, event, this);
			ef.doWork();
		}
	}
}

void ThreadPool::push(int Option, Event *e)
{
	switch(Option){
	case IN:
		while(!qIn_.push(e));
		break;
	case OUT:
		while(!qOut_.push(e));
		break;
	default:
		while(!qError_.push(e));
		break;
	}
}
	
ServerTcpEvent* ThreadPool::GetIOEvent(){
	mutex_.lock();
	ServerTcpEvent *retP = NULL;
	ioPool_.GetObject(retP);
	mutex_.unlock();
	return retP;
}

void ThreadPool::SaveIOEvent(ServerTcpEvent* p){
	mutex_.lock();
	ioPool_.SaveObject(p);
	mutex_.unlock();
}

Event* ThreadPool::GetEvent(string name){
	return eventPool_.GetSpaceEvent(name);
}

void ThreadPool::SaveEvent(string name, Event* p){
	eventPool_.SaveEvent(name, p);
}
