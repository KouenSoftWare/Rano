#pragma once

#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>

#include "Buffer.h"

#define MAXREADBUFFER 65535
#define LISTENQ 128

using namespace std;

class Event;
class EventLoop;
class Epoll;

class TcpConnection
{
public:
	TcpConnection(Epoll* e):isWrite_(true){
		epoll_ = e;	
	}
	~TcpConnection();

	int OnError();
	int OnRead(vector<boost::shared_ptr<Event> >&);
	int OnWrite();
	int Fd();
	int write(boost::shared_ptr<Event>&);//用来发送数据的
	void SetNonBlock();//构造函数，默认就会调用
	void SetIpPort(const string&, const string&);
	void setFd(int f);
	int send();
	bool openServer();
	bool openClient();
private:
	string ip_;
	int port_;

	Buffer writeBuffer_; //缓冲区
	Buffer readBuffer_; //缓冲区

	bool isWrite_; //能否进行写入
	bool open_;//是否已经开启某种模式
	int fd_;
	Epoll* epoll_;
};

void TcpRecvEventToOtherEvent(boost::shared_ptr<Event>&, boost::weak_ptr<EventLoop>&);
