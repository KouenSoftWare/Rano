#pragma once

#include <string.h>

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
};
