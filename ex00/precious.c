/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 21:13:50 by jkalia            #+#    #+#             */
/*   Updated: 2017/08/01 22:06:25 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void insertEnd(t_node **start, char value)
{
	if (*start == NULL)
	{
		t_node	*newNode = malloc(sizeof(t_node));
		newNode->c = value;
		newNode->prev = newNode;
		newNode->next = newNode;
		*start = newNode;
		return;
	}
	t_node *lastNode = (*start)->prev;
	t_node	*newNode = malloc(sizeof(t_node));
	newNode->c = value;
	newNode->prev = lastNode;
	newNode->next = *start;
	(*start)->prev = newNode;
	lastNode->next = newNode;
}

void displayAll(t_node **start)
{
	t_node *begin = *start;
	t_node *ptr = (*start)->next;

	printf("%c", begin->c);
	while (ptr != begin)
	{
		printf("%c", ptr->c);
		ptr = ptr->next;
	}
}

char letterout(t_node **start, int index)
{
	int		i = 0;
	if (index == 0)
		return ((*start)->c);
	if (index < 0)
	{
		index *= -1;
		while (i < index)
		{
			(*start) = (*start)->prev;
			++i;
		}
		return ((*start)->c);
	}
	else
	{
		while (i < index)
		{
			(*start) = (*start)->next;
			++i;
		}
		return ((*start)->c);
	}
}

char *display(t_node *ptr, int *text, int size)
{
	char *out = malloc(size + 1);
	out[size] = 0;
	for (int i = 0; i < size; i++)
	{
		out[i] = letterout(&ptr, text[i]);
	}
	return (out);
}

char *precious(int *text, int size)
{
	t_node	*start = NULL;
	int		cs_len = strlen(CS);
	char	charset[cs_len];
	charset[cs_len] = 0;
	memcpy(charset, CS, cs_len);
	if (size == 0)
	{
		printf("Empty File\n");
		return (NULL);
	}
	for (int i = 0; i < cs_len; i++)
		insertEnd(&start, charset[i]);
	return (display(start, text, size));
}
