/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 15:57:45 by jkalia            #+#    #+#             */
/*   Updated: 2017/08/02 16:11:26 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_queue *queueInit(void)
{
	t_queue *init = malloc(sizeof(t_queue));
	init->first = NULL;
	init->last = NULL;
	return (init);
}

char *dequeue(struct s_queue *queue)
{
	if (queue->first == NULL)
	{
		return (NULL);
	}
	if (queue->first == queue->last)
	{
		t_node *ptr = queue->first;
		queue->first = queue->last = NULL;
		return (ptr->message);
	}
	t_node *ptr = queue->first;
	t_node *next = ptr->next;
	queue->first = next;
	return (ptr->message);
}

void enqueue(struct s_queue *queue, char *message)
{
	if (queue->first == NULL)
	{
		t_node *newNode = malloc(sizeof(t_node));
		newNode->next = NULL;
		newNode->message = strdup(message);
		queue->first = queue->last = newNode;
		return;
	}
	t_node *newNode = malloc(sizeof(t_node));
	newNode->next = NULL;
	newNode->message = strdup(message);
	t_node *lastNode = queue->last;
	lastNode->next = newNode;
	queue->last = newNode;
	return;
}

void printAll(t_queue *queue)
{
	t_node *ptr = queue->first;
	while (ptr != NULL)
	{
		printf("%s\n", ptr->message);
		ptr = ptr->next;
	}
}

char *peek(struct s_queue *queue)
{
	t_node *ptr = queue->first;
	return (ptr->message);
}

int isEmpty(struct s_queue *queue)
{
	if (queue->first == NULL && queue->last == NULL)
		return (1);
	return (0);
}
