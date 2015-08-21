#pragma once

#include "CMutex.h"

class AutoMutex
{
	CMutex &mutex_;
public:
	AutoMutex(CMutex mutex):
		mutex_(mutex)
	{
		mutex_.lock();
	}

	~AutoMutex(){
		mutex_.unlock();
	}
};
