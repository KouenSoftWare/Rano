#pragma once 

#include "EventSourceBase.h"
#include "EventTargetBase.h"
#include "TcpConnection.h"
#include "IOPool.h"

#define MAXEVENTS 64

using namespace std;

class Epoll:
	public EventSourceBase,
	public EventTargetBase
{
	int DelListen(const int&,map<int, boost::shared_ptr<TcpConnection> >::iterator&);
public:
	Epoll();
	~Epoll(){}

	void Add(TcpConnection*);

	void GetEvents(vector<Event*>&);
	int SendEvents(Event* &event);

	void SetSourceID(int, int);
	void SaveEvent(Event*&);
	void LoadEvents(int, vector<Event*>&);
private:
	map<int, boost::shared_ptr<TcpConnection> > listen_list_;
	int epfd_;
	epoll_event	waitEP_[MAXEVENTS];	
	TcpConnection server_;

	map<int, int> mapSourceID_;
	map<int, vector<Event*> > mapSourceIDToSaveEvents_;
	IOPool<ServerTcpEvent> ioPool_;
};
