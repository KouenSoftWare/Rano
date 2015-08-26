#include "MessageLoop.h"
#include "StateMachine.h"
#include "Epoll.h"
#include "Common.h"

MessageLoop::MessageLoop()
{
	ep_ = new Epoll();	
}

void MessageLoop::Loop()
{
	vector<google::protobuf::Message*> vMsgEvent;
	HeadProtocol* headProtocol;
	while(1){
		vMsgEvent.clear();
		ep_->GetMessages(vMsgEvent);
		for(int i = 0; i < int(vMsgEvent.size()); i++){
			headProtocol = (HeadProtocol*)vMsgEvent[i];		
			executeList_[headProtocol->proto_body_name()](vMsgEvent[i], this);
		}
		for(int i = 0; i < int(vecMsgs_.size()); i++){
			ep_->SendMessages(vecMsgs_[i]);	
		}
		vecMsgs_.clear();
	}
}

void MessageLoop::PushMessage(google::protobuf::Message* msg)
{
	vecMsgs_.push_back(msg);
}

void MessageLoop::reg(string name, FuncPtr f)
{
	executeList_[name] = f;
}

