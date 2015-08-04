#pragma once

#include "CommunicationsProtocol.h"
#include <string>
#include <string.h>

using namespace std;

class Event
{
protected:
	char name_[32];

public:
	level1 l1;

	void setName(const char* name){
		memcpy(name_, name, 32);
	}

	const char* getName() const{
		return name_;
	}

};
