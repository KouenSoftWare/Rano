#pragma once 

#include <map>
#include <sys/epoll.h>
#include "EventSourceBase.h"
#include "TcpConnection.h"

#define MAXEVENTS 64

using namespace std;


class TcpConnection;
class Event;

class Epoll:
	public EventSourceBase
{
public:
	Epoll();
	~Epoll(){}

	void Add(TcpConnection*);

	void GetEvents(vector<boost::shared_ptr<Event> >&);
private:
	map<int, boost::shared_ptr<TcpConnection> > listen_list_;
	int epfd_;
	epoll_event	waitEP_[MAXEVENTS];	
	TcpConnection server_;
};
