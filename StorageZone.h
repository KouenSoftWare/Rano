#pragma once

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <map>
#include <vector>

using namespace std;

class TcpConnection;
class Event;

class StorageZone{
private:
	StorageZone(){};
	StorageZone(const StorageZone& rhs){};
	StorageZone& operator =(const StorageZone& rhs);

	static StorageZone* instance_;
	map<int, boost::weak_ptr<TcpConnection> > mapOnObject_;
	map<int, vector<Event*> > mapOnEvents_;
public:
	static StorageZone* GetInstance();
	
	void Addition(int, Event*&);
	void Addition(int, boost::weak_ptr<TcpConnection>);
	void GetEvent(int, vector<Event*>&);
	bool GetObject(int, boost::shared_ptr<TcpConnection>&);
};
