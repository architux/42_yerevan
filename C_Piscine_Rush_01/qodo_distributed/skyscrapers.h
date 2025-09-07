/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscrapers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:05:27 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/07 14:05:45 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKYSCRAPERS_H
#define SKYSCRAPERS_H

#include <unistd.h>
#include <stdlib.h>

int	str_len(char *s);
void	write_char(char c);
void	write_str(char *s);
void	write_int(int n);
void	print_grid(int *grid, int n);

int	count_numbers(char *s);
int	parse_numbers(char *s, int *out, int max);
int	validate_vals(int *vals, int n);

int	is_safe(int *grid, int n, int pos, int val);
int	row_complete(int *grid, int n, int row);
int	col_complete(int *grid, int n, int col);
int	next_empty(int *grid, int n, int start);
int	apply_obvious(int *grid, int n, int *clues);

int	check_row_clues(int *grid, int n, int row, int *clues);
int	check_col_clues(int *grid, int n, int col, int *clues);
int	check_row_partial(int *grid, int n, int row, int *clues);
int	check_col_partial(int *grid, int n, int col, int *clues);

int	solve(int *grid, int n, int pos, int *clues);

#endif
