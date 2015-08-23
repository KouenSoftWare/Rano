#pragma once

#include "CommunicationsProtocol.h"

typedef boost::function<int(Event*&, ThreadPool*)> FuncPtr;

class Event
{
private:
	char name_[32];
	
public:
	void setName(const char* name){
		memcpy(name_, name, 32);
	}

	const char* getName() const{
		return name_;
	}

};
