#pragma once

//sizeof(level1) == (36+24=60)
struct level1{
	char			featureCode[4];	
	unsigned int	level2Size;
	unsigned int	sourceID;
	unsigned int	targetID;
	unsigned int	jumpCount;
	unsigned int	missCount;
	unsigned int	googleProtocolID;
	unsigned long	serialNumber;
	char			persist[24];
};
