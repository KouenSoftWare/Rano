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
#include <stdio.h>
#include <sys/epoll.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <assert.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h> /* See NOTES */
#include <errno.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <signal.h>

#include "Protocol.pb.h"

using namespace std;

class MessageLoop;
typedef boost::function<int(google::protobuf::Message*, MessageLoop*)> FuncPtr;
