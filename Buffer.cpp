#include "Buffer.h"
bool Buffer::hasData()
{
	return !storage_.empty();
}

char* Buffer::data()
{
	return &storage_[0];
}

int Buffer::length()
{
	return storage_.size();
}

void Buffer::append(string& msg)
{
	for(size_t i=0; i!= msg.size();i++){
		storage_.push_back(msg[i]);
	}
}

void Buffer::append(char* msg, size_t size)
{
	for(size_t i=0; i< size;i++){
		storage_.push_back(msg[i]);
	}
}

void Buffer::update(size_t size)
{
	vector<char> temp;
	for(size_t i=size; i!=storage_.size(); i++){
		temp.push_back(storage_[i]);	
	}
	storage_.swap(temp);
}
