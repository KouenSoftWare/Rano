#include "EventFactory.h"

Event* EventFactory::GetEvent(char* buf, int size)
{
	Event* ret = create();
	memcpy(ret, buf, size);		
	return ret;
}
