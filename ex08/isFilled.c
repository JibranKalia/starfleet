
#include "header.h"

int isFilled(unsigned int parkingRow)
{
	unsigned int tmp = parkingRow;
	unsigned int msb = 0;
	while (tmp >>= 1)
		++msb;
	tmp = (1 << (msb + 1)) - 1;
	return ((parkingRow ^ tmp) ? 0 : 1);
}
