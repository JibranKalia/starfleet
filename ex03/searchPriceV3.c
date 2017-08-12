/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 06:15:09 by jkalia            #+#    #+#             */
/*   Updated: 2017/08/01 07:04:15 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

size_t hash(char *input)
{
	unsigned long hash = 5381;
	int c;
	while ((c = *input++))
		hash = ((hash << 5) + hash) + c;
	return (hash);
}

struct s_dict *dictInit(int capacity)
{
	t_dict *ret;

	ret = malloc(sizeof(t_dict));
	ret->capacity = capacity;
	ret->items = malloc(sizeof(t_item *) * (capacity + 1));
	return (ret);
}

int dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	int		index;
	t_item	*newitem;
	t_item	*ptr;

	newitem = malloc(sizeof(t_item));
	if (!newitem)
		return (-1);
	newitem->key = strdup(key);
	newitem->value = value;
	index = hash(key) % dict->capacity;
	ptr = dict->items[index];
	newitem->next = ptr;
	dict->items[index] = newitem;
	return (0);
}

struct s_art *dictSearch(struct s_dict *dict, char *key)
{
	int index;
	t_item *ptr;

	index = hash(key) % dict->capacity;
	ptr = dict->items[index];
	while (ptr != NULL)
	{
		if (strcmp(ptr->key, key) == 0)
			return (ptr->value);
		ptr = ptr->next;
	}
	return (NULL);
}
