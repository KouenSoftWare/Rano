#include "StorageZone.h"
#include "TcpConnection.h"
#include <assert.h>

StorageZone* StorageZone::instance_ = NULL;

StorageZone* StorageZone::GetInstance()
{
	if(instance_ == NULL){
		instance_ = new StorageZone();
	}
	return instance_;
}

void StorageZone::Addition(int id, boost::shared_ptr<Event> pEvent)
{
	map<int, vector<boost::shared_ptr<Event> > >::iterator iter = mapOnEvents_.find(id);
	if(iter == mapOnEvents_.end()){
		vector<boost::shared_ptr<Event> > events;
		mapOnEvents_.insert(pair<int, vector<boost::shared_ptr<Event> > >(id, events));			
		iter = mapOnEvents_.find(id);
		assert(iter != mapOnEvents_.end());
	}
	iter->second.push_back(pEvent);
}

void StorageZone::Addition(int id, boost::weak_ptr<TcpConnection> pTcp)
{
	map<int, boost::weak_ptr<TcpConnection> >::iterator iter = mapOnObject_.find(id);
	if(iter == mapOnObject_.end()){
		mapOnObject_.insert(pair<int, boost::weak_ptr<TcpConnection> >(id, pTcp));		
	}else{
		iter->second = pTcp;	
	}
}

void StorageZone::GetEvent(int id, vector<boost::shared_ptr<Event> >& rhs)
{
	map<int, vector<boost::shared_ptr<Event> > >::iterator iter = mapOnEvents_.find(id);
	if(iter != mapOnEvents_.end()){
		iter->second.swap(rhs);	
	}		
}
bool StorageZone::GetObject(int id, boost::shared_ptr<TcpConnection>& rhs)
{
	map<int, boost::weak_ptr<TcpConnection> >::iterator iter = mapOnObject_.find(id);
	if(iter == mapOnObject_.end()){
		return false;
	}else{
		if(iter->second.expired()){
			map<int, vector<boost::shared_ptr<Event> > >::iterator iterEvent = mapOnEvents_.find(id);
			if(iterEvent == mapOnEvents_.end()){
				mapOnObject_.erase(iter);
			}else if(iterEvent->second.size() == 0){
				mapOnObject_.erase(iter);
				mapOnEvents_.erase(iterEvent);
			}
			return false;
		}	
		rhs = iter->second.lock();
		return true;
	}
}
