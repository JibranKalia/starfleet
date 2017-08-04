/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findShifted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 19:12:25 by jkalia            #+#    #+#             */
/*   Updated: 2017/08/03 20:56:13 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdbool.h>

int search(int *arr, int low, int high, int value)
{
	if (low > high)
		return -1;
	int mid = (low + high) / 2;
	if (arr[mid] == value)
		return (mid);

	if (arr[low] <= arr[mid])
	{
		if (value >= arr[low] && value <= arr[mid])
			return (search(arr, low, mid - 1, value));
		return (search(arr, mid + 1, high, value));
	}
	if (value >= arr[mid] && value <= arr[high])
		return (search(arr, mid + 1, high, value));
	return (search(arr, low, mid - 1, value));
}

int searchShifted(int *rocks, int length, int value)
{
	if (rocks[0] == value)
		return (0);
	int out;
	out = search(rocks, 1, length - 1, value);
	while (rocks[out - 1] == value && out > 0)
		--out;
	return (out);
}
