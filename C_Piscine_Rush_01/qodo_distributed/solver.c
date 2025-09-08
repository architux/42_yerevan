/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 05:27:12 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/08 05:27:14 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checks.h"
#include "solver.h"

static int	apply_column_one_top(int *grid, int n, int col)
{
	int	idx;

	idx = 0 * n + col;
	if (grid[idx] != 0 && grid[idx] != n)
		return (0);
	grid[idx] = n;
	return (1);
}

static int	apply_column_one_bottom(int *grid, int n, int col)
{
	int	idx;

	idx = (n - 1) * n + col;
	if (grid[idx] != 0 && grid[idx] != n)
		return (0);
	grid[idx] = n;
	return (1);
}

static int	apply_column_n_top(int *grid, int n, int col)
{
	int	i;
	int	idx;

	i = 0;
	while (i < n)
	{
		idx = i * n + col;
		if (grid[idx] != 0 && grid[idx] != (i + 1))
			return (0);
		grid[idx] = i + 1;
		i++;
	}
	return (1);
}

static int	apply_column_n_bottom(int *grid, int n, int col)
{
	int	i;
	int	idx;

	i = 0;
	while (i < n)
	{
		idx = (n - 1 - i) * n + col;
		if (grid[idx] != 0 && grid[idx] != (i + 1))
			return (0);
		grid[idx] = i + 1;
		i++;
	}
	return (1);
}

static int	apply_row_one_left(int *grid, int n, int row)
{
	int	idx;

	idx = row * n + 0;
	if (grid[idx] != 0 && grid[idx] != n)
		return (0);
	grid[idx] = n;
	return (1);
}

static int	apply_row_one_right(int *grid, int n, int row)
{
	int	idx;

	idx = row * n + (n - 1);
	if (grid[idx] != 0 && grid[idx] != n)
		return (0);
	grid[idx] = n;
	return (1);
}

static int	apply_row_n_left(int *grid, int n, int row)
{
	int	j;
	int	idx;

	j = 0;
	while (j < n)
	{
		idx = row * n + j;
		if (grid[idx] != 0 && grid[idx] != (j + 1))
			return (0);
		grid[idx] = j + 1;
		j++;
	}
	return (1);
}

static int	apply_row_n_right(int *grid, int n, int row)
{
	int	j;
	int	idx;

	j = 0;
	while (j < n)
	{
		idx = row * n + (n - 1 - j);
		if (grid[idx] != 0 && grid[idx] != (j + 1))
			return (0);
		grid[idx] = j + 1;
		j++;
	}
	return (1);
}

int	apply_obvious(int *grid, int n, int *clues)
{
	int	j;
	int	i;
	int	ok;

	ok = 1;
	j = 0;
	while (j < n)
	{
		if (clues[j] == 1)
			if (!apply_column_one_top(grid, n, j))
				return (0);
		if (clues[j] == n)
			if (!apply_column_n_top(grid, n, j))
				return (0);
		if (clues[n + j] == 1)
			if (!apply_column_one_bottom(grid, n, j))
				return (0);
		if (clues[n + j] == n)
			if (!apply_column_n_bottom(grid, n, j))
				return (0);
		j = j + 1;
	}
	i = 0;
	while (i < n)
	{
		if (clues[2 * n + i] == 1)
			if (!apply_row_one_left(grid, n, i))
				return (0);
		if (clues[2 * n + i] == n)
			if (!apply_row_n_left(grid, n, i))
				return (0);
		if (clues[3 * n + i] == 1)
			if (!apply_row_one_right(grid, n, i))
				return (0);
		if (clues[3 * n + i] == n)
			if (!apply_row_n_right(grid, n, i))
				return (0);
		i = i + 1;
	}
	return (ok);
}

int	solve(int *grid, int n, int pos, int *clues)
{
	int	next;
	int	val;
	int	row;
	int	col;

	next = next_empty(grid, n, pos);
	if (next == -1)
	{
		if (check_final(grid, n, clues))
			return (1);
		return (0);
	}
	val = 1;
	while (val <= n)
	{
		if (is_safe(grid, n, next, val))
		{
			grid[next] = val;
			row = next / n;
			col = next % n;
			if (row_complete(grid, n, row))
			{
				if (!check_row_clues(grid, n, row, clues))
				{
					grid[next] = 0;
					val++;
					continue ;
				}
			}
			if (col_complete(grid, n, col))
			{
				if (!check_col_clues(grid, n, col, clues))
				{
					grid[next] = 0;
					val++;
					continue ;
				}
			}
			if (solve(grid, n, next + 1, clues))
				return (1);
			grid[next] = 0;
		}
		val++;
	}
	return (0);
}
