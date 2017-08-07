/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 10:14:35 by jkalia            #+#    #+#             */
/*   Updated: 2017/08/07 11:38:26 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define LIMIT 4
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

char *handleComplement(char *a)
{
	memmove(&a[0], &a[1], 4);
	for (int i = LIMIT - 1; i >= 0; i--)
	{
		a[i] = (a[i] == '1') ? '0' : '1';
	}
	return (a);
}

char *getAnd(char *a, char *b)
{
	char *ret = calloc(LIMIT, sizeof(char));
	for (int i = LIMIT - 1; i >= 0; i--)
	{
		ret[i] = (GETBIT(a[i]) & GETBIT(b[i])) + '0';
	}
	return (ret);
}

char *getOr(char *a, char *b)
{
	char *ret = calloc(LIMIT, sizeof(char));
	if (a[0] == '~')
		a = handleComplement(a);
	if (b[0] == '~')
		b = handleComplement(b);
	for (int i = LIMIT - 1; i >= 0; i--)
	{
		ret[i] = (GETBIT(a[i]) | GETBIT(b[i])) + '0';
	}
	return (ret);
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
