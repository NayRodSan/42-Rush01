/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 21:10:17 by ltakahas          #+#    #+#             */
/*   Updated: 2019/12/01 21:24:08 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

int		*generate_zero(int dim);
int		*generate_clues(int dim, char *params);
int		*solve_skyscraper_normal(int *matrix, int dim);
int		*solve_skyscraper_reverse(int *matrix, int dim);
int		check_uncompletion(int *matrix, int dim);
int		row_observation(int *pos, int *mat, int dim);
int		col_observation(int *pos, int *mat, int dim);
int		row_no_repetition(int *position, int *mat, int dim);
int		col_no_repetition(int *position, int *mat, int dim);
int		validation(int *pos, int *mat, int dim);
void	check_col_up(int *mat, int *clues, int dim, int i);
void	check_col_down(int *mat, int *clues, int dim, int i);
void	check_row_left(int *mat, int *clues, int dim, int i);
void	edge_clue_initialization(int *mat, int *clues, int dim);
void	print_matrix(int *matrix, int dim);
void	ft_putchar(char c);
void	skyscraper(char *params);
char	*removespaces(char *str);
int		valid01(char *clue);
int		valid02(char *clue);
int		valid03(char *clue);
int		valid04(char *clue);
int		valid05_1(char *clue);
int		valid05_2(char *clue);
int		valid06_1(char *clue);
int		valid06_2(char *clue);
int		valid07_1(char *clue);
int		valid07_2(char *clue);
int		check_error_1(char *clue);
int		check_error_2(char *clue);
int		check_error_3(char *clue);
#endif
