#include "StateMachine.h"	
	
map<int, map<int, int> > StateMachine::jumpMap_;
map<int, FuncPtr> StateMachine::statusFunction_;

void StateMachine::Set(int currentState,int returnState,  int nextState)
{
	map<int, int>& temp = jumpMap_[currentState];
	temp[returnState] = nextState;
}

void StateMachine::Set(int currentState, FuncPtr f)
{
	statusFunction_[currentState] = f;
}

void StateMachine::Remove(int currentState)
{
	map<int, FuncPtr>::iterator iter = statusFunction_.find(currentState);
	if(iter != statusFunction_.end())
	  statusFunction_.erase(iter);
}

void StateMachine::Set(int currentState)
{
	currentState_ = currentState;
}

int StateMachine::Get()
{
	return currentState_;
}

void StateMachine::Execute(Event* pEvent, ThreadPool* tp)
{
	map<int, FuncPtr>::iterator iter = statusFunction_.find(currentState_);
	if(iter == statusFunction_.end()){
		cout << "<!>遇到缺失的状态值 : " << currentState_ << "<!>" << endl;
		return;
	}
	FuncPtr f = statusFunction_[currentState_];
	int ret = f(pEvent, tp);	
	currentState_ = jumpMap_[currentState_][ret];
}
