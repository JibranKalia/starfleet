/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 22:10:27 by jkalia            #+#    #+#             */
/*   Updated: 2017/08/02 14:12:56 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void displayAll(t_node *start)
{
	t_node *ptr = start;
	while (ptr)
	{
		printf("%s ", ptr->word);
		ptr = ptr->next;
	}
}

void printReverse(t_node *lst)
{
	static int i = 0;
	if (lst == NULL)
		return;
	++i;
	printReverse(lst->next);
	--i;
	printf("%s", lst->word);
	printf("%c", i == 0 ? '\n' : ' ');
}
