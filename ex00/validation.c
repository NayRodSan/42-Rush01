/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 07:07:10 by aroque            #+#    #+#             */
/*   Updated: 2019/12/01 18:31:19 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		validation(int *pos, int *mat, int dim)
{
	int rr;
	int cr;
	int ro;
	int co;

	rr = row_no_repetition(pos, mat, dim);
	cr = col_no_repetition(pos, mat, dim);
	ro = row_observation(pos, mat, dim);
	co = col_observation(pos, mat, dim);
	if (rr && cr)
	{
		return (1);
	}
	return (0);
}

int		row_observation(int *pos, int *mat, int dim)
{
	int k;
	int minor;
	int observation;
	int *checker;

	k = 0;
	minor = 0;
	observation = 0;
	checker = mat + dim * ((pos - mat) / dim);
	while (k < dim)
	{
		if (*checker > minor)
		{
			observation++;
			minor = *checker;
		}
		checker++;
		k++;
	}
	return (observation);
}

int		col_observation(int *pos, int *mat, int dim)
{
	int k;
	int minor;
	int observation;
	int *checker;

	k = 0;
	minor = 0;
	observation = 0;
	checker = mat + ((pos - mat) % dim);
	while (k < dim)
	{
		if (*checker > minor)
		{
			observation++;
			minor = *checker;
		}
		checker += dim;
		k++;
	}
	return (observation);
}

int		row_no_repetition(int *position, int *mat, int dim)
{
	int k;
	int row;
	int *checker;

	k = 0;
	row = (position - mat) / dim;
	while (k < dim)
	{
		checker = mat + row * dim + k;
		if (*checker == *position && checker != position)
		{
			return (0);
		}
		k++;
	}
	return (1);
}

int		col_no_repetition(int *position, int *mat, int dim)
{
	int k;
	int col;
	int *checker;

	k = 0;
	col = (position - mat) % dim;
	while (k < dim)
	{
		checker = mat + k * dim + col;
		if (*checker == *position && checker != position)
		{
			return (0);
		}
		k++;
	}
	return (1);
}
