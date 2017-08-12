/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 22:33:48 by jkalia            #+#    #+#             */
/*   Updated: 2017/08/02 14:07:04 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_stack *stackInit(void)
{
	t_stack *top = malloc(sizeof(t_stack));
	top->item = NULL;
	return (top);
}

void *pop(struct s_stack *stack)
{
	if (stack->item == NULL)
		return (NULL);
	t_item *top = stack->item;
	if (top->next == NULL)
	{
		stack->item = NULL;
		return (top);
	}
	stack->item = top->next;
	return (top);
}

void push(struct s_stack *stack, char *word)
{
	if (stack->item == NULL)
	{
		t_item *newItem = malloc(sizeof(t_item));
		newItem->next = NULL;
		newItem->word = strdup(word);
		stack->item = newItem;
		return;
	}
	t_item *newItem = malloc(sizeof(t_item));
	newItem->next = stack->item;
	newItem->word = strdup(word);
	stack->item = newItem;
}

void printAll(t_stack *stack)
{
	t_item *ptr = stack->item;
	while (ptr != NULL)
	{
		printf("%s\n", ptr->word);
		ptr = ptr->next;
	}
}

void printReverseV2(struct s_node *lst)
{
	t_stack *top;
	top = stackInit();
	while (lst != NULL)
	{
		push(top, lst->word);
		lst = lst->next;
	}
	t_item *tmp;
	while ((tmp = pop(top)) != NULL)
	{
		printf("%s", tmp->word);
		printf("%c", top->item ? ' ' : '\n');
	}
}
