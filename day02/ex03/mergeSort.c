/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 17:35:42 by jkalia            #+#    #+#             */
/*   Updated: 2017/08/03 18:17:32 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void merge(t_player **arr, int low, int mid, int high)
{
	t_player *tmp[high-low];
	int i = low;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= high) {
		if (arr[i]->score >= arr[j]->score)
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}
	while (i <= mid)
		tmp[k++] = arr[i++];

	while (j <= high)
		tmp[k++] = arr[j++];

	k--;
	while (k >= 0)
	{
		arr[low + k] = tmp[k];
		k--;
	}
}

void mymerge(t_player **players, int low, int high)
{
	if (low < high)
	{
		int m = (low + high) / 2;
		mymerge(players, low, m);
		mymerge(players, m + 1, high);
		merge(players, low, m, high);
	}
}

struct s_player **mergeSort(struct s_player **players)
{
	int		len = 0;
	while (players[len])
		++len;
	mymerge(players, 0, len - 1);
	return (players);
}
