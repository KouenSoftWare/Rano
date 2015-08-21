#include "Buffer.h"

bool Buffer::hasData()
{
	return length_?true:false;
}

char* Buffer::data()
{
	return &storage_[0];
}

int Buffer::length()
{
	return length_; 
}

Buffer::~Buffer()
{
	storage_.clear();
}

void Buffer::append(const char* msg, size_t size)
{
	if(storage_.size()-length_ < size){
		storage_.resize(storage_.size()*2 + size*2);
	}
	memcpy(&storage_[length_], msg, size);
	length_ += size;
}

void Buffer::update(size_t size)
{
	if(length_ >= int(size)){
		memcpy(&storage_[0], &storage_[size], length_-size);
		length_ -= size;
	}else{
		length_ = 0;
	}
}

