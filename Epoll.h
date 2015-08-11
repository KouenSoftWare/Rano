#pragma once 

#include <map>
#include <sys/epoll.h>
#include "EventSourceBase.h"
#include "EventTargetBase.h"
#include "TcpConnection.h"

#define MAXEVENTS 64

using namespace std;


class TcpConnection;
class Event;

class Epoll:
	public EventSourceBase,
	public EventTargetBase
{
	int DelListen(const int&,map<int, boost::shared_ptr<TcpConnection> >::iterator&);
public:
	Epoll();
	~Epoll(){}

	void Add(TcpConnection*);

	void GetEvents(vector<boost::shared_ptr<Event> >&);
	int SendEvents(boost::shared_ptr<Event> &event);
private:
	map<int, boost::shared_ptr<TcpConnection> > listen_list_;
	int epfd_;
	epoll_event	waitEP_[MAXEVENTS];	
	TcpConnection server_;
};
