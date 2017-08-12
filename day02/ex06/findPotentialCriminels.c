/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPotentialCriminels.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 21:30:03 by jkalia            #+#    #+#             */
/*   Updated: 2017/08/03 22:47:22 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>
#define RANGE 10

void countSort(t_criminal **arr, int n, int den)
{
	int count[RANGE];
	t_criminal *output[n];
	int i;
	for (i = 0; i < RANGE; i++)
		count[i] = 0;
	for (i = 0; i < n; i++)
		count[(arr[i]->description / den) % 10]++;
	for (i = 1; i < RANGE; i++)
	{
		count[i] += count[i - 1];
	}
	for (i = n - 1; i >= 0; i--)
	{
		--count[(arr[i]->description / den) % 10];
		output[count[(arr[i]->description / den) % 10]]= arr[i];
	}
	for (i = 0; i < n; i++)
	{
		arr[i] = output[i];
	}
}

void sortCriminals(struct s_criminal **criminals)
{
	int len = 0;
	while (criminals[len])
		len++;

	for (int i = 0; i < 7; i++)
		countSort(criminals, len, pow(10, i));
}

int binarySearch(t_criminal **arr, int left, int right, int value)
{
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (arr[middle]->description == value)
			return middle;
		if (arr[middle]->description < value)
			left = middle + 1;
		else
			right = middle - 1;
	}
	return -1;
}

int getDescription(struct s_info *info)
{
	int ret;

	ret = info->gender * pow(10, 6)
		+ info->height * pow(10, 5)
		+ info->hairColor * pow(10, 4)
		+ info->eyeColor * pow(10, 3)
		+ info->glasses * pow(10, 2)
		+ info->tattoo * pow(10, 1)
		+ info->piercing * pow(10, 0);
	return (ret);
}

struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info)
{
	int value = getDescription(info);
	int len = 0;
	int index = 0;
	int stopindex = 0;

	while (criminals[len])
		++len;
	index = binarySearch(criminals, 0, len - 1, value);
	if (index == -1)
		return (0);
	while (index > 0 && criminals[index]->description == value)
		--index;
	++index;
	stopindex = index;
	while (stopindex < len && criminals[stopindex]->description == value)
		++stopindex;
	criminals[stopindex] = 0;
	return (&criminals[index]);
}
