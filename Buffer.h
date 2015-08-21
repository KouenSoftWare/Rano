#pragma once

#include <vector>
#include <string>
#include <string.h>

using namespace std;

class Buffer
{
	vector<char> storage_;
	int length_;
public:
	Buffer():length_(0){}
	bool hasData();	
	char* data();
	int length();
	void append(const char*, size_t);
	void update(size_t);
	void clear(){
		storage_.clear();
	}
};
