/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 14:03:48 by jkalia            #+#    #+#             */
/*   Updated: 2017/08/03 14:28:12 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void insertionSort(struct s_player **players)
{
	int		i = 1;
	int		j;
	t_player *key;

	while (players[i])
	{
		j = i - 1;
		key = players[i];
		while (j >= 0 && players[j]->score < key->score)
		{
			players[j + 1] = players[j];
			--j;
		}
		++j;
		players[j] = key;
		++i;
	}
}
