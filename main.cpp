#include "MessageLoop.h"
#include "StateMachine.h"
#include "Common.h"
/*
 * 状态图：
 *	10001 --0--> 10002 --0--> 10004
 *	    	       |-----1--> 10003 ----0---->10004
 *								|-------1---->10001 
 */

int test_10001(google::protobuf::Message* msg, MessageLoop* ml)
{
	TestProtocol* test = (TestProtocol*)msg;
	cout << "10001 Say: " <<  test->msg() << endl;
	test->set_msg("10003");
	return 0;
}

int test_10002(google::protobuf::Message* msg, MessageLoop* ml)
{
	TestProtocol* test = (TestProtocol*)msg;
	cout << "10002 Say:" <<  test->msg() << endl;
	if(test->msg() == "10003"){
		test->set_msg("10004");
		return 1;	
	}else
		return 0;
}

int test_10003(google::protobuf::Message* msg, MessageLoop* ml)
{
	TestProtocol* test = (TestProtocol*)msg;
	cout << "10003 Say:" <<  test->msg() << endl;
	if(test->msg() == "10001"){
		return 1;	
	}else{
		test->set_msg("Over!");
		return 0;
	}
}

int test_10004(google::protobuf::Message* msg, MessageLoop* ml)
{
	TestProtocol* test = (TestProtocol*)msg;
	cout << "10004 Say:" << test->msg() << endl;
	return 0;
}

int TestFunction(google::protobuf::Message* msg, MessageLoop* ml)
{
	HeadProtocol* head = (HeadProtocol*)msg;
	TestProtocol tp;
	tp.ParseFromString(head->proto_body_buffer());
	tp.set_status(StateMachine::Execute(tp.status(), &tp));		
	string body;
	tp.SerializeToString(&body);
	head->set_target_id(head->source_id());
	head->set_source_id(10001);
	head->set_proto_body_buffer(body);
	head->set_proto_body_name("TestProtocol");
	ml->PushMessage(msg);	
	return 0;	
}

int main()
{
	MessageLoop loop;
	StateMachine::Set(&loop);
	StateMachine::Set(10001, 0, 10002);
	StateMachine::Set(10002, 0, 10004);
	StateMachine::Set(10002, 1, 10003);
	StateMachine::Set(10003, 0, 10004);
	StateMachine::Set(10003, 1, 10001);
	StateMachine::Set(10001, boost::bind(&test_10001, _1, _2));
	StateMachine::Set(10002, boost::bind(&test_10002, _1, _2));
	StateMachine::Set(10003, boost::bind(&test_10003, _1, _2));
	StateMachine::Set(10004, boost::bind(&test_10004, _1, _2));
	loop.reg("TestProtocol", boost::bind(&TestFunction, _1, _2));
	loop.Loop();
	return 0;
}
