#pragma once

#include "CommunicationsProtocol.h"

class Event
{
protected:
	string name_;

public:
	level1 l1;

	void setName(string& name){
		name = name_;
	}

	const string& getName() const{
		return name_;
	}

};
