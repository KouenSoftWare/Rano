#pragma once

#include "Event.h"

class StateMachine{
	static map<int, map<int, int> > jumpMap_;
	static map<int, FuncPtr> statusFunction_;

	int currentState_;
public:	
	void Set(int);
	int Get();
	void Execute(Event*, ThreadPool*);

    static void Set(int, int, int);
	static void Set(int, FuncPtr);
	static void Remove(int);
};

/*
 *	首先需要注册：
 *		StateMachine::Set(10001, 0, 10002);
 *		StateMachine::Set(10001, 1, 10003);
 *		StateMachine::Set(10001, 2, 10004);
 *		StateMachine::Set(10002, 0, 10004);
 *		StateMachine::Set(10003, 0, 10004);
 *	相当与状态图:	
 *		10001---->10002---->10004
 *        |------>10003---->10004
 *        |------>10004
 *
 *  设置每个状态值对应的处理函数
 *  根据每个函数的返回值决定跳转的对象
 */
