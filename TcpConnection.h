#pragma once

#include "Buffer.h"
#include "Event.h"
#include "IOPool.h"
#include "ServerTcpEvent.h"

#define MAXREADBUFFER 65535
#define LISTENQ 128

class TcpConnection
{
public:
	TcpConnection(Epoll* e,IOPool<ServerTcpEvent> *ioPool):isWrite_(true){
		ioPool_ = ioPool;
		epoll_ = e;	
	}
	~TcpConnection();

	int OnError();
	int OnRead(vector<Event*>&);
	int OnWrite();
	int Fd();
	int write(Event*&);//用来发送数据的
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
	IOPool<ServerTcpEvent>* ioPool_;
};

int TcpRecvEventToOtherEvent(Event*&, ThreadPool*);
