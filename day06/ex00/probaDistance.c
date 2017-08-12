
#include "header.h"

double probaDistance(int dist, int *locations, int n)
{
	int favorable = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (locations[j] - locations[i] > dist)
				++favorable;
		}
	}
	long possible = (n * (n-1)) / 2;
	return ((double)favorable / (double)possible);
}
