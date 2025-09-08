/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 05:25:47 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/08 06:16:10 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKS_H
#define CHECKS_H

int	visible_count(int *arr, int n);
int	row_complete(int *grid, int n, int row);
int	col_complete(int *grid, int n, int col);
int	check_row_clues(int *grid, int n, int row, int *clues);
int	check_col_clues(int *grid, int n, int col, int *clues);
int	is_safe(int *grid, int n, int pos, int val);
int	next_empty(int *grid, int n, int start);
int	check_final(int *grid, int n, int *clues);

#endif
