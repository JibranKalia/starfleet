/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touchStore.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 13:26:20 by jkalia            #+#    #+#             */
/*   Updated: 2017/08/03 13:45:45 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void sortStones(struct s_stone **stone)
{
	int		tmp;
	bool	swapped = true;
	t_stone *head;
	t_stone *lastptr = NULL;
	t_stone *next = NULL;

	while (swapped == true)
	{
		swapped = false;
		head = *stone;
		while (head->next != lastptr)
		{
			next = head->next;
			if (head->size > next->size)
			{
				tmp = next->size;
				next->size = head->size;
				head->size = tmp;
				swapped = true;
			}
			head = head->next;
		}
		lastptr = head;
		printStone(*stone);
	}
}
