#pragma once

#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>

using namespace std;

class Event;

class TcpConnection
{
public:
	TcpConnection():isWrite_(true), bufferSpace_(true){}
	~TcpConnection();

	int OnError();
	int OnRead(vector<boost::shared_ptr<Event> >&);
	int OnWrite();
	int Fd();
	int write(string&);//用来发送数据的
	void SetNonBlock();//构造函数，默认就会调用
	void SetIpPort(const string&, const string&);
	bool openServer();
private:
	bool isWrite_; //能否进行写入
	bool bufferSpace_;//缓冲区是否还有数据
	int fd_;
};
