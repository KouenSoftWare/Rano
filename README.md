# Rano
Distributed event stream processing framework

Users in the use of the framework, you need to register a number of events and event handling functions to ServerNode EventLoop, you can also choose to register the event source, etc..

Use examples: Main.cpp
Currently supported languages: C++

[v0.0]	MasterNode: main responsibility distributed framework of global data security, backup; responsible for management RouteNode.
[v0.1]	RouteNode: main responsibility distribution, load balancing, etc.
[v0.2]	ServerNode: main responsibility for receiving and handling events.

#RouteNode Ver 0.1
1 Set up the RouteNode processing framework;
2 Comfirm that Communication Protocol:Google Protocol
3 Confirm that the State Machine

#ServerNode Ver 0.2

1 adding thread pool
2 adding object pool
3 pass the pressure test


#ServerNode Ver 0.1
1 set up the ServerNode event stream processing framework
2 adding Epoll as an event source
3 add Tcp support
