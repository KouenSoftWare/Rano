#pragma once

#include "Event.h"

class ServerTcpEvent:
	public Event
{
private:
	int fd_;
public:
	void setFd(int &i){
		fd_ = i;
	}
	const int& getFd() const{
		return fd_;
	}
};
