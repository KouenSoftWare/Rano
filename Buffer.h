#pragma once

#include <vector>
#include <string>

using namespace std;

class Buffer
{
	vector<char> storage_;
public:
	bool hasData();	
	char* data();
	int length();
	void append(string&);
	void append(char*, size_t);
	void update(size_t);
	void clear(){
		storage_.clear();
	}
};
