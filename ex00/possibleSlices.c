#include "header.h"

#define MIN(a,b) (((a)<(b))?(a):(b))

void printArray(int p[], int n)
{
	printf("\n");
	if (n == 0){
		printf("NULL\n");
		return ;
	}

	printf("[");
	int i = 0;
	for (i = 0; i < n; i++){
		printf("%d", p[i]);
		if (i + 1 < n)
			printf(", ");
	}
	printf("]\n\n");
}

void recursion(int n, int i)
{
	static int arr[100];
	for (int l = 0; l < 5; l++)
		printf("%d ", arr[l]);
	printf("\n");
	if (n == 0)
	{
		printArray(arr, i);
	}
	else if (n > 0)
	{
		int k;
		for (k = 1; k<= n; k++)
		{
			arr[i] = k;
			recursion(n-k, i+1);
		}
	}
}

void printPossibleSlices(int pizzaSize)
{
	recursion(pizzaSize, 0);
}
