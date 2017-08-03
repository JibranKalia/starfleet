/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 16:19:37 by jkalia            #+#    #+#             */
/*   Updated: 2017/08/02 17:14:39 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		g_capacity;

struct s_stack *initStack()
{
	t_stack *top = malloc(sizeof(t_stack));
	top->elem = NULL;
	top->sum = 0;
	return (top);
}

void push(struct s_stack *stack, int energy)
{
	if (stack->elem == NULL)
	{
		t_elem *newElem = malloc(sizeof(t_elem));
		newElem->next = NULL;
		newElem->energy = energy;
		stack->elem = newElem;
		return;
	}
	t_elem *newElem = malloc(sizeof(t_elem));
	newElem->next = stack->elem;
	newElem->energy = energy;
	stack->elem = newElem;
}

int pop(struct s_stack *stack)
{
	if (stack->elem == NULL)
		return (0);
	t_elem *top = stack->elem;
	if (top->next == NULL)
	{
		stack->elem = NULL;
		return (top->energy);
	}
	stack->elem = top->next;
	free(top);
	return (top->energy);
}

struct s_tank *initTank(void)
{
	t_tank *init = calloc(1, sizeof(t_tank));
	init->n = 0;
	init->stacks = calloc(100, sizeof(t_stack*));
	g_capacity = 100;
	return (init);
}

void tankPush(struct s_tank *tank, int energy)
{
	int idx = tank->n;
	if (tank->stacks[idx] == NULL)
	{
		t_stack *newStack = initStack();
		push(newStack, energy);
		newStack->sum += energy;
		tank->stacks[idx] = newStack;
	}
	else if ((tank->stacks[idx]->sum + energy) > 1000)
	{
		++idx;
		++tank->n;
		if (g_capacity == idx)
		{
			printf("Not Enough space. Sorry\n");
			return;
		}
		t_stack *newStack = initStack();
		push(newStack, energy);
		newStack->sum += energy;
		tank->stacks[idx] = newStack;
	}
	else
	{
		t_stack *tmp = tank->stacks[idx];
		push(tmp, energy);
		tmp->sum += energy;
	}
}

int tankPop(struct s_tank *tank)
{
	int		ret;
	int		idx = tank->n;
	if (tank->stacks[idx] == NULL)
	{
		return (0);
	}
	t_stack *tmp = tank->stacks[idx];
	ret = pop(tmp);
	tmp->sum -= ret;
	if (tmp->sum == 0)
	{
		--tank->n;
	}
	return (ret);
}

void visual(t_tank *tank)
{
	int		max = tank->n;

	for (int i = 0; i <= max; i++)
	{
		printf("Stack %d: Sum = %d\n", i, tank->stacks[i]->sum);
	}
}
