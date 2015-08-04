#pragma once

#include "Event.h"

class ServerTcpEvent:
	public Event
{
private:
	int fd_;
	vector<char> buf_;
public:
	void setFd(int &i){
		fd_ = i;
	}
	const int& getFd() const{
		return fd_;
	}

	void setBuf(vector<char>& vc){
		buf_.swap(vc);
	}
	const vector<char>& getBuf() const{
		return buf_;
	}
};
