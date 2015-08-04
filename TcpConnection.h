#pragma once

#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>

using namespace std;

class Event;

class TcpConnection
{
public:
	TcpConnection();
	~TcpConnection();

	int OnError();
	int OnRead(vector<boost::shared_ptr<Event> >&);
	int OnWrite();
	int Fd();
	void SetNonBlock();//构造函数，默认就会调用
	void SetIpPort(const string&, const string&);
	bool openServer();
private:
	bool isWrite_; //能否进行写入
	int fd_;
};
