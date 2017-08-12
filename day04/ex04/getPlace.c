#include "header.h"

int getPlace(unsigned int parkingRow, int pos)
{
	int test = (1 << pos);
	return ((parkingRow & test) >> pos);
}
