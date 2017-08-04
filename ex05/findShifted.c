/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findShifted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 19:12:25 by jkalia            #+#    #+#             */
/*   Updated: 2017/08/03 19:27:47 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdbool.h>

int searchShifted(int *rocks, int length, int value)
{
	int i = 0;
	bool flag = false;
	if (rocks[0] <= value)
	{

		for (i = 0; i < length; i++)
		{
			if (rocks[i] == value)
				break;
		}
		return ((i == length) ? -1 : i);
	}
	else
	{
		i = length - 1;
		while (i > 0)
		{
			if (rocks[i] == value)
			{
				flag = true;
				break;
			}
			--i;
		}
		if (flag == true)
		{
			while (rocks[i] == value)
			{
				--i;
			}
			++i;
			return (i);
		}
	}
	return (-1);
}
