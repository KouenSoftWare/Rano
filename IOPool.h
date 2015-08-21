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
