#include "EventFactory.h"
#include <stdio.h>
#include <string.h>

boost::shared_ptr<Event> EventFactory::GetEvent(char* buf, int size)
{
	boost::shared_ptr<Event> ret = create();
	memcpy(ret.get(), buf, size);		
	return ret;
}
