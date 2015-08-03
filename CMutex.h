#pragma once 

#include<pthread.h>

class CMutex
{
public:
	CMutex(){
		pthread_mutex_init(&mutex_, NULL);
	}

	~CMutex(){
		pthread_mutex_destroy(&mutex_);
	}

	void lock(){
		pthread_mutex_lock(&mutex_); 
	}

	void unlock(){
		pthread_mutex_unlock(&mutex_); 
	}
private:
	pthread_mutex_t mutex_;
};
