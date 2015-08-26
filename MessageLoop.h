#pragma once

class Epoll;

class MessageLoop{
	Epoll* ep_;
public:
	MessageLoop();

	void Loop();
};
