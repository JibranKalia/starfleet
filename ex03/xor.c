/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 10:14:35 by jkalia            #+#    #+#             */
/*   Updated: 2017/08/07 15:09:57 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define LIMIT 6
#define GETBIT(j) ((j) - '0')
#define TOCHAR(j) ((j) + '0');
int toInt(char *bits)
{
	char *tmp = calloc(LIMIT, sizeof(char));
	memcpy(tmp, bits, LIMIT);
	int ret = 0;
	int base = 1;
	for (int j = LIMIT - 1; j >= 0; j--)
	{
		ret += GETBIT(tmp[j]) * base;
		base = base * 2;
	}
	free(tmp);
	return (ret);
}

char *getXor(char *a, char *b)
{
	char tmp[LIMIT];
	for (int i = 0; i < LIMIT; i++)
	{
		tmp[i] = (GETBIT(a[i]) ^ GETBIT(b[i])) + '0';
	}
	memcpy(a, tmp, LIMIT);
	return (a);
}
