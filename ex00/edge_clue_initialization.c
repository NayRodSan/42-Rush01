/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_clue_initialization.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 07:06:09 by aroque            #+#    #+#             */
/*   Updated: 2019/12/01 18:28:08 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush.h"

void	edge_clue_initialization(int *mat, int *clues, int dim)
{
	int i;
	int k;

	i = 0;
	while (i < dim)
	{
		check_col_up(mat, clues, dim, i);
		check_col_down(mat, clues, dim, i);
		check_row_left(mat, clues, dim, i);
		if (*(clues + dim + i) == dim)
		{
			k = 1;
			while (k <= dim)
			{
				*(mat + dim * (dim - k) + i) = k;
				k++;
			}
		}
		else if (*(clues + dim + i) == 1)
		{
			*(mat + dim * (dim - 1) + i) = dim;
		}
		i++;
	}
}

void	check_col_down(int *mat, int *clues, int dim, int i)
{
	int k;

	if (*(clues + 3 * dim + i) == dim)
	{
		k = 1;
		while (k <= dim)
		{
			*(mat + (i + 1) * dim - k) = k;
			k++;
		}
	}
	else if (*(clues + 3 * dim + i) == 1)
	{
		*(mat + (i + 1) * dim - 1) = dim;
	}
}

void	check_col_up(int *mat, int *clues, int dim, int i)
{
	int k;

	if (*(clues + 2 * dim + i) == dim)
	{
		k = 1;
		while (k <= dim)
		{
			*(mat + i * dim + k - 1) = k;
			k++;
		}
	}
	else if (*(clues + 2 * dim + i) == 1)
	{
		*(mat + i * dim) = dim;
	}
}

void	check_row_left(int *mat, int *clues, int dim, int i)
{
	int k;

	if (*(clues + i) == dim)
	{
		k = 1;
		while (k <= dim)
		{
			*(mat + i + dim * (k - 1)) = k;
			k++;
		}
	}
	else if (*(clues + i) == 1)
	{
		*(mat + i) = dim;
	}
}
