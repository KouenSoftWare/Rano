#pragma once

#include "Protocol.pb.h"
#include "TcpConnection.h"
#include "Common.h"

#define MAXEVENTS 1024

using namespace std;
using namespace ::google::protobuf;

class TcpConnection;
class Message;

class Epoll
{
	int DelListen(const int&,map<int, boost::shared_ptr<TcpConnection> >::iterator&);
public:
	Epoll();
	~Epoll(){}

	void GetMessages(vector<google::protobuf::Message*>&);
	int SendMessages(google::protobuf::Message* &);
	void SetSourceID(int fd, int sId);

private:
	map<int, boost::shared_ptr<TcpConnection> > listen_list_;
	int epfd_;
	epoll_event	waitEP_[MAXEVENTS];	
	TcpConnection server_;

	map<int, int> mapSourceID_;
};

