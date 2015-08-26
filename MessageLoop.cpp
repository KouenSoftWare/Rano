#include "MessageLoop.h"
#include "Epoll.h"
#include "Common.h"

MessageLoop::MessageLoop()
{
	ep_ = new Epoll();	
}

void MessageLoop::Loop()
{
	vector<google::protobuf::Message*> vMsgEvent;
	while(1){
		vMsgEvent.clear();
		ep_->GetMessages(vMsgEvent);
	}
}

