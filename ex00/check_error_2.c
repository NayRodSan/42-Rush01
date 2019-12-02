/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 09:36:13 by ltakahas          #+#    #+#             */
/*   Updated: 2019/12/01 21:18:37 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush.h"

int		check_error_2(char *clue)
{
	if (valid05_1(clue) == 1)
		return (1);
	if (valid05_2(clue) == 1)
		return (1);
	if (valid06_1(clue) == 1)
		return (1);
	if (valid06_2(clue) == 1)
		return (1);
	return (0);
}

int		valid05_1(char *clue)
{
	int i;
	int col_u1;

	col_u1 = 0;
	i = 0;
	while (i < 8)
	{
		if (clue[i] == '1')
			col_u1++;
		i++;
	}
	if (col_u1 == 1)
		return (0);
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
}

int		valid05_2(char *clue)
{
	int i;
	int col_d1;

	col_d1 = 0;
	i = 8;
	while (i < 16)
	{
		if (clue[i] == '1')
			col_d1++;
		i++;
	}
	if (col_d1 == 1)
		return (0);
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
}

int		valid06_1(char *clue)
{
	int i;
	int row_l1;

	row_l1 = 0;
	i = 16;
	while (i < 23)
	{
		if (clue[i] == '1')
			row_l1++;
		i++;
	}
	if (row_l1 == 1)
		return (0);
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
}

int		valid06_2(char *clue)
{
	int i;
	int row_r1;

	row_r1 = 0;
	i = 24;
	while (i < 31)
	{
		if (clue[i] == '1')
			row_r1++;
		i++;
	}
	if (row_r1 == 1)
		return (0);
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
}
