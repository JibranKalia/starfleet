/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 10:14:35 by jkalia            #+#    #+#             */
/*   Updated: 2017/08/07 14:46:33 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

char *handleComplement(char *a)
{
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

char *handleNegative(char *bits)
{
	bits = handleComplement(bits);
	bits = getSum(bits, "000001");
	return bits;
}

int toInt(char *bits)
{
	char *tmp = calloc(LIMIT, sizeof(char));
	memcpy(tmp, bits, LIMIT);
	if (tmp[0] == '~')
	{
		memmove(&tmp[0], &tmp[1], 4);
		tmp = handleComplement(tmp);
	}
	int flag = 1;
	if (tmp[0] == '1')
	{
		tmp = handleNegative(tmp);
		flag = -1;
	}
	int ret = 0;
	int base = 1;
	for (int j = LIMIT - 1; j >= 0; j--)
	{
		ret += GETBIT(tmp[j]) * base;
		base = base * 2;
	}
	free(tmp);
	return (ret * flag);
}

char *leftShift(char *bin, int k)
{
	char tmp[LIMIT];
	memcpy(tmp, bin, LIMIT);
	int i = LIMIT - k;
	while (i < LIMIT)
	{
		bin[i] = '0';
		++i;
	}
	memcpy(bin, &tmp[k], LIMIT - k);
	return (bin);
}

char *rightShift(char *bin, int k)
{
	char sign = (bin[0] == '0') ? '0' : '1';
	char tmp[LIMIT];
	int i = 0;
	memcpy(tmp, bin, LIMIT);
	while (i < k)
	{
		bin[i] = sign;
		++i;
	}
	memcpy(&bin[i], tmp, LIMIT - i);
	return (bin);
}
