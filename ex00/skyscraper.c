/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscraper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:59:43 by aroque            #+#    #+#             */
/*   Updated: 2019/12/01 18:33:42 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdlib.h>

int		*solve_skyscraper_normal(int *matrix, int dim)
{
	int k;
	int *first;

	first = matrix;
	k = 0;
	while (k <= dim * dim)
	{
		if (!validation(matrix, first, dim) || *matrix == 0)
		{
			*(matrix) += 1;
		}
		else
		{
			matrix++;
			k++;
		}
	}
	return (first);
}

int		*solve_skyscraper_reverse(int *matrix, int dim)
{
	int k;
	int *first;

	first = matrix;
	matrix += dim * dim;
	k = 0;
	while (k <= dim * dim)
	{
		if (!validation(matrix, first, dim) || *matrix == 0)
		{
			*(matrix) += 1;
		}
		else
		{
			matrix--;
			k++;
		}
	}
	return (first);
}

int		check_uncompletion(int *matrix, int dim)
{
	int i;

	i = 0;
	while (i < dim * dim)
	{
		if (*(matrix + i) > dim)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	print_matrix(int *ptr, int dim)
{
	int i;

	i = 0;
	while (i < dim * dim)
	{
		ft_putchar(*ptr + '0');
		ft_putchar(' ');
		ptr++;
		i++;
		if (i % dim == 0)
		{
			ft_putchar('\n');
		}
	}
}

void	skyscraper(char *params)
{
	int i;
	int *elem;
	int *clues;
	int dim;

	i = 0;
	dim = 4;
	clues = generate_clues(dim, params);
	elem = generate_zero(dim);
	edge_clue_initialization(elem, clues, dim);
	elem = solve_skyscraper_normal(elem, dim);
	if (check_uncompletion(elem, dim))
	{
		free(elem);
		elem = generate_zero(dim);
		edge_clue_initialization(elem, clues, dim);
		elem = solve_skyscraper_reverse(elem, dim);
	}
	print_matrix(elem, dim);
}
