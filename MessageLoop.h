#pragma once

#include "Common.h"

class Epoll;

class MessageLoop{
	Epoll* ep_;
	map<string, FuncPtr> executeList_;
	vector<google::protobuf::Message*> vecMsgs_;
public:
	MessageLoop();

	void Loop();

	void reg(string, FuncPtr);

	void PushMessage(google::protobuf::Message* msg);
};
