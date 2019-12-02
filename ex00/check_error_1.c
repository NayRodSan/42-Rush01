/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 09:36:13 by ltakahas          #+#    #+#             */
/*   Updated: 2019/12/01 20:20:50 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush.h"

int		check_error_1(char *clue)
{
	if (valid01(clue) == 1)
		return (1);
	if (valid02(clue) == 1)
		return (1);
	if (valid03(clue) == 1)
		return (1);
	if (valid04(clue) == 1)
		return (1);
	return (0);
}

int		valid01(char *clue)
{
	int		i;

	i = 0;
	while (i < 31)
	{
		if (i % 2 == 0 && (clue[i] < '1' || clue[i] > '4'))
		{
			write(1, "Error\n", 6);
			return (1);
		}
		if (i % 2 == 1 && clue[i] != ' ')
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

int		valid02(char *clue)
{
	if (31 != 31)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int		valid03(char *clue)
{
	int i;
	int count1;
	int count4;

	i = 0;
	count1 = 0;
	count4 = 0;
	while (i < 31)
	{
		if (clue[i] == '1')
			count1++;
		if (clue[i] == '4')
			count4++;
		i++;
	}
	if (count1 != 4 || count4 > 4)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int		valid04(char *clue)
{
	int i;
	int count2;
	int count3;

	i = 0;
	count2 = 0;
	count3 = 0;
	while (i < 31)
	{
		if (clue[i] == '2')
			count2++;
		if (clue[i] == '3')
			count3++;
		i++;
	}
	if (count2 > 8 || count2 < count3)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
