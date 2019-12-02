/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 15:46:25 by aroque            #+#    #+#             */
/*   Updated: 2019/12/01 21:09:47 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush.h"

int		main(int argc, char **argv)
{
	char *params;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (check_error_1(argv[1]) == 1)
		return (1);
	if (check_error_2(argv[1]) == 1)
		return (1);
	if (check_error_3(argv[1]) == 1)
		return (1);
	params = removespaces(argv[1]);
	skyscraper(params);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
