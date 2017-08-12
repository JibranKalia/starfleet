/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyGameBoard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 17:40:04 by jkalia            #+#    #+#             */
/*   Updated: 2017/08/02 17:48:18 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_node *cloneGameBoard(struct s_node *node)
{
	t_node *clone = malloc(sizeof(t_node));
	t_node *ptr = clone;
	while (node != NULL)
	{
		ptr->random = node->random;
		ptr->next = node->next;
		node = node->next;
	}
}
