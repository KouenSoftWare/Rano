#pragma once

struct level1{
	char			featureCode[4];	
	unsigned int	level2Size;
	unsigned int	sourceID;
	unsigned int	targetID;
	unsigned int	jumpCount;
	unsigned int	missCount;
	unsigned long	serialNumber;
	char			level2Name[32];	//放消息的名字
};
