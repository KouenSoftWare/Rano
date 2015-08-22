# Rano
Distributed event stream processing framework

Users in the use of the framework, you need to register a number of events and event handling functions to ServerNode EventLoop, you can also choose to register the event source, etc..

Use examples: Main.cpp

Currently supported languages: C++

MasterNode: main responsibility distributed framework of global data security, backup; responsible for management RouteNode.

RouteNode: main responsibility distribution, load balancing, etc.

ServerNode: main responsibility for receiving and handling events.

#Ver 0.2

1 adding thread pool

2 adding object pool

3 pass the pressure test


#Ver 0.1

1 set up the ServerNode event stream processing framework

2 adding Epoll as an event source

3 add Tcp support
