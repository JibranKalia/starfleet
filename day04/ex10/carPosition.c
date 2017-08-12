/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 08:57:29 by jkalia            #+#    #+#             */
/*   Updated: 2017/08/08 09:02:52 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int powerof2(unsigned int n)
{
	if (n == 1)
		return (1);
	if ((n & (n - 1)) == 0)
		return (1);
	return (-1);
}

int carPosition(unsigned int parkingRow)
{
	if (powerof2(parkingRow) == -1)
		return (-1);
	unsigned int count = 0;
	while (parkingRow)
	{
		parkingRow = parkingRow >> 1;
		++count;
	}
	return (count - 1);
}
