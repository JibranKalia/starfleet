/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 09:29:58 by jkalia            #+#    #+#             */
/*   Updated: 2017/07/31 10:27:24 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>

int  searchPrice(struct s_art **arts, char *name)
{
	int name_len;
	if (!name || !arts || !*arts)
		return (-1);
	name_len = strlen(name);
	while (*arts)
	{
		if (strncmp((*arts)->name, name, name_len) == 0)
			return ((*arts)->price);
		arts++;
	}
	return (-1);
}
