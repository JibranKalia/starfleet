#include <stdio.h>

int rightmostCar(unsigned int parkingRow)
{
	int pos;
	int tmp;
	tmp = 1;
	for (pos = 0; pos < 32; pos++)
	{
		if (parkingRow & tmp)
			break;
		tmp <<= 1;
	}
	return (pos);
}
