#pragma once

#include <queue>
#include <iostream>
using namespace std;

template<typename T>
class IOPool{
private:
	queue<T*> spaceQueue_;
	int length_;
public:
	IOPool(int number = 10240);
	~IOPool();
	void GetObject(T*&);
	void SaveObject(T*&);

};

template<typename T>
IOPool<T>::IOPool(int number):
	spaceQueue_(),
	length_(number)
{
	for(int i = 0; i < length_; i++){
		spaceQueue_.push(new T);
	}	
}

template<typename T>
IOPool<T>::~IOPool()
{
	T* t;
	for(int i = 0; i < spaceQueue_.size(); i++){
		t = spaceQueue_.front();
		delete t;
		spaceQueue_.pop();
	}	
}


template<typename T>
void IOPool<T>::GetObject(T*& object)
{
	if(spaceQueue_.empty()){
		for(int i = 0; i < length_; i++){
			spaceQueue_.push(new T);
		}	
		cout << "IO—Pool too more big : " << length_ << endl;
		length_ *= 2;
	}
	object = spaceQueue_.front();
	spaceQueue_.pop();
}

template<typename T>
void IOPool<T>::SaveObject(T*& object)
{
	spaceQueue_.push(object);
}
