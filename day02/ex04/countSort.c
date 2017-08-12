/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:32:26 by jkalia            #+#    #+#             */
/*   Updated: 2017/08/03 21:12:49 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define RANGE 15

void countSort(unsigned char *utensils, int n)
{
	int count[RANGE + 1];
	char output[n];
	int i;
	bzero(count, sizeof(count));
	for (i = 0; i < n; i++)
		count[utensils[i]] += 1;
	for (i = 1; i <= RANGE; i++)
	{
		count[i] += count[i - 1];
	}
	for (i = 0; i < n; i++)
	{
		--count[utensils[i]];
		output[count[utensils[i]]] = utensils[i];
	}
	for (i = 0; i < n; i++)
	{
		utensils[i] = output[i];
	}
}
