#include "StateMachine.h"	
#include "MessageLoop.h"
	
map<int, map<int, int> > StateMachine::jumpMap_;
map<int, FuncPtr> StateMachine::statusFunction_;
MessageLoop* StateMachine::ml_ = NULL;

void StateMachine::Set(MessageLoop* ml)
{
	ml_ = ml;	
}

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

int StateMachine::GetNextState(int current, int retValue)
{
	return jumpMap_[current][retValue];
}
int StateMachine::Execute(int state,google::protobuf::Message* msg)
{
	int ret = statusFunction_[state](msg, ml_);
	return GetNextState(state, ret);
}
