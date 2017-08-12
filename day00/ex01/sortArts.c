/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 10:49:53 by jkalia            #+#    #+#             */
/*   Updated: 2017/07/31 16:25:02 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int			lexcmp(void *a, void *b)
{
	return (strcmp(((struct s_art *)(a))->name, ((struct s_art *)(b))->name));
}

void	qsort_swap(void **v, int i, int j)
{
	void *tmp;

	tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

void	ft_qsort(void **v, int left, int right, int (*comp) (void *, void *))
{
	int	i;
	int	last;

	if (left >= right)
		return ;
	qsort_swap(v, left, (left + right) / 2);
	last = left;
	i = left + 1;
	while (i <= right)
	{
		if (((*comp)(v[i], v[left])) < 0)
			qsort_swap(v, ++last, i);
		++i;
	}
	qsort_swap(v, left, last);
	ft_qsort(v, left, last - 1, comp);
	ft_qsort(v, last + 1, right, comp);
}


void  sortArts(struct s_art **arts)
{
	int				len = 0;

	while (arts[len] != 0)
		++len;
	ft_qsort((void**)arts, 0, len - 1, lexcmp);
}

