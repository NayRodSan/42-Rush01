/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:23:13 by aroque            #+#    #+#             */
/*   Updated: 2019/12/01 18:27:29 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*generate_zero(int dim)
{
	int i;
	int *mat;
	int *first;

	i = 0;
	mat = (int *)malloc(dim * dim * sizeof(int));
	first = mat;
	while (i < dim * dim)
	{
		*mat = 0;
		mat++;
		i++;
	}
	return (first);
}

int		*generate_clues(int dim, char *params)
{
	int i;
	int *clues;

	i = 0;
	clues = (int *)malloc(dim * dim * sizeof(int));
	while (i < dim * dim)
	{
		*(clues + i) = params[i] - '0';
		i++;
	}
	return (clues);
}
