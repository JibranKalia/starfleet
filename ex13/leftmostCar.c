#include <limits.h>

int leftmostCar(unsigned int parkingRow)
{
	int pos = 0;
	while (parkingRow)
	{
		parkingRow >>= 1;
		++pos;
	}
	return (pos - 1);
}
