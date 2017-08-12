/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 16:27:44 by jkalia            #+#    #+#             */
/*   Updated: 2017/07/31 16:55:02 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <math.h>

int binarySearch(struct s_art **arts, char *target, int start, int end)
{
	int		middle;

	if (start > end)
		return (-1);
	middle = (int)floor((start + end) / 2);
	if (strcmp(target, arts[middle]->name) < 0)
		return (binarySearch(arts, target, start, middle - 1));
	else if (strcmp(target, arts[middle]->name) > 0)
		return (binarySearch(arts, target, middle + 1, end));
	return (arts[middle]->price);
}

int searchPrice(struct s_art **arts, int n, char *name)
{
	return (binarySearch(arts, name, 0, n - 1));
}
