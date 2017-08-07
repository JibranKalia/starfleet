/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 10:14:35 by jkalia            #+#    #+#             */
/*   Updated: 2017/08/07 10:54:22 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>
#define LIMIT 6
#define GETBIT(j) ((j) - '0')

char *getSum(char *a, char *b)
{
	char c;
	char ret[LIMIT];

	bzero(ret, LIMIT);
	for (int i = LIMIT - 1; i >= 0; i--)
	{
		ret[i] = ((GETBIT(a[i]) ^ GETBIT(b[i])) ^ c) + '0';
		c = ((GETBIT(a[i]) & GETBIT(b[i])) | (GETBIT(a[i]) & c)) | (GETBIT(b[i]) & c);
	}
	strncpy(a, ret, LIMIT);
	return (a);
}

int toInt(char *bits)
{
	int ret = 0;
	int base = 1;
	for (int j = LIMIT - 1; j >= 0; j--)
	{
		ret += GETBIT(bits[j]) * base;
		base = base * 2;
	}
	return (ret);
}
