#include "header.h"

void swap(t_player **array, int left, int right)
{
	t_player *tmp;
	tmp = array[left];
	array[left] = array[right];
	array[right] = tmp;
}

int partition(t_player **array, int left, int right, int pivot)
{
	while (left <= right)
	{
		while (array[left]->score > pivot)
			++left;
		while (array[right]->score < pivot)
			right--;
		if (left <= right)
		{	
			swap(array, left, right);
			right--;
			left++;
		}
	}
	return left;
}

void myqsort(t_player **players, int left, int right)
{
	if (left >= right)
		return;
	int pivot = players[(left + right) / 2]->score;
	int index = partition(players, left, right, pivot);
	myqsort(players, left, index - 1);
	myqsort(players, index, right);
}
void quickSort(struct s_player **players)
{
	int		len = 0;
	while (players[len])
		++len;
	myqsort(players, 0, len -1);
}
