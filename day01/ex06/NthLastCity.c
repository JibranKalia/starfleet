/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NthLastCity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 17:31:42 by jkalia            #+#    #+#             */
/*   Updated: 2017/08/02 17:36:36 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

char *NthLastCity(struct s_city *city, int n)
{
	t_city *ref = city;
	t_city *main = city;
	for (int i = 0; i <= n; i++)
	{
		if (ref == NULL)
			return (NULL);
		ref = ref->next;
	}
	while (ref != NULL)
	{
		main = main->next;
		ref = ref->next;
	}
	return (main->name);
}
