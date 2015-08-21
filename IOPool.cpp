#include "IOPool.h"

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
		cout << "IO—Pool不够了，进行扩充！" << endl;
	}
	object = spaceQueue_.front();
	spaceQueue_.pop();
}

template<typename T>
void IOPool<T>::SaveObject(T*& object)
{
	spaceQueue_.push(object);
}
