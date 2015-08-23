#pragma once


#include <string>
#include <iostream>
#include <vector>
#include <map>

#include <boost/smart_ptr.hpp>
#include <boost/lockfree/queue.hpp>
#include <boost/thread/thread.hpp>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/function.hpp>
#include <boost/utility.hpp>
#include <boost/lockfree/queue.hpp>

#include <string.h>
#include <sys/epoll.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <assert.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>          /* See NOTES */
#include <errno.h>
#include <sys/socket.h>
#include <fcntl.h>


using namespace std;

class Event;
class EventFactory;
class EventSourceBase;
class EventTargetBase;
class ThreadPool;
class ProtocolFactory;
class Epoll;
class EventFunc;
class EventLoop;
/*
struct level1{
	char			featureCode[4];	
	unsigned int	level2Size;
	unsigned int	sourceID;
	unsigned int	targetID;
	unsigned int	jumpCount;
	unsigned int	missCount;
	unsigned long	serialNumber;
	char			level2Name[32];	//放消息的名字

	void set(const char* f, int l, int s, int t, int j, int m, int se, const char* le)
	{
		memcpy(&featureCode[0], f, 4);
		memcpy(&level2Name[0], le, 32);
		level2Size = l;
		sourceID = s;
		targetID = t;
		jumpCount = j;
		missCount = m;
		serialNumber = se;
	}
};*/
