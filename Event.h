#pragma once

class Event
{
protected:
	string name_;

public:
	void setName(string& name){
		name = name_;
	}

	const string& getName() const{
		return name_;
	}

};
