/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 09:36:13 by ltakahas          #+#    #+#             */
/*   Updated: 2019/12/01 21:25:15 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush.h"

int		check_error_3(char *clue)
{
	if (valid07_1(clue) == 1)
		return (1);
	if (valid07_2(clue) == 1)
		return (1);
	return (0);
}

int		valid07_1(char *clue)
{
	if (clue[6] == '1' && clue[24] != '1')
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (clue[24] == '1' && clue[6] != '1')
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (clue[14] == '1' && clue[30] != '1')
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (clue[30] == '1' && clue[14] != '1')
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int		valid07_2(char *clue)
{
	if (clue[8] == '1' && clue[22] != '1')
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (clue[22] == '1' && clue[8] != '1')
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (clue[0] == '1' && clue[15] != '1')
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (clue[15] == '1' && clue[0] != '1')
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
