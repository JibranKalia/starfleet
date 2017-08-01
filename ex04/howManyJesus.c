/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 08:29:30 by jkalia            #+#    #+#             */
/*   Updated: 2017/08/01 16:03:39 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>
#include <string.h>
#include <stdio.h>

#define d 256
const int PRIME_BASE = 257;
const int PRIME_MOD = 1000000007;

long hash(char *name)
{
	int		len = strlen(name);
	long	ret = 0;
	for (int i = 0; i < len; i++)
	{
		ret = ret * PRIME_BASE + name[i];
		ret %= PRIME_MOD;
	}
	return ret;
}


int		howManyJesus(char *bible, char *jesus)
{
	int		needle_len = strlen(jesus);
	int		haystack_len = strlen(bible);
	long	jesus_hash = hash(jesus);
	long	bible_hash = 0;
	long	power;
	int		count = 0;

	for (int i = 0; i < needle_len; i++)
	{
		power = (power * PRIME_BASE) % PRIME_MOD;
	 	bible_hash = bible_hash*PRIME_BASE + bible[i];
	 	bible_hash %= PRIME_MOD;
	}

	printf("Jesus Hash = %ld\n", jesus_hash);
	printf("Bible Hash = %ld\n", bible_hash);
	for (int i = 0; i <= haystack_len - needle_len; i++)
	{
		if (bible_hash == jesus_hash)
		{
			printf("Here\n");
			++count;
		}
		if (i < haystack_len - needle_len)
		{
			bible_hash -= power * bible[i - needle_len] % PRIME_MOD;
			if (bible_hash < 0)
				bible_hash += PRIME_MOD;
		}
	}
	return (count);
}
