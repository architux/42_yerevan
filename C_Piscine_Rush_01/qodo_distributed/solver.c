/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:02:59 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/07 14:05:08 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscrapers.h"

static void	fill_col_inc(int *grid, int n, int col)
{
	int	i;
	int	v;

	i = 0;
	v = 1;
	while (i < n)
	{
		grid[i * n + col] = v;
		v++;
		i++;
	}
}

static void	fill_col_dec(int *grid, int n, int col)
{
	int	i;
	int	v;

	i = 0;
	v = n;
	while (i < n)
	{
		grid[i * n + col] = v;
		v--;
		i++;
	}
}

static void	fill_row_inc(int *grid, int n, int row)
{
	int	j;
	int	v;

	j = 0;
	v = 1;
	while (j < n)
	{
		grid[row * n + j] = v;
		v++;
		j++;
	}
}

static void	fill_row_dec(int *grid, int n, int row)
{
	int	j;
	int	v;

	j = 0;
	v = n;
	while (j < n)
	{
		grid[row * n + j] = v;
		v--;
		j++;
	}
}

static int	set_if_compat(int *grid, int idx, int val)
{
	int	ok;

	ok = 1;
	if (grid[idx] != 0 && grid[idx] != val)
		ok = 0;
	if (ok)
		grid[idx] = val;
	return (ok);
}

static int	apply_full_cols(int *grid, int n, int *clues)
{
	int	i;
	int	ok;

	i = 0;
	ok = 1;
	while (i < n)
	{
		if (clues[i] == n)
			fill_col_inc(grid, n, i);
		if (clues[n + i] == n)
			fill_col_dec(grid, n, i);
		i++;
	}
	return (ok);
}

static int	apply_full_rows(int *grid, int n, int *clues)
{
	int	i;
	int	ok;

	i = 0;
	ok = 1;
	while (i < n)
	{
		if (clues[2 * n + i] == n)
			fill_row_inc(grid, n, i);
		if (clues[3 * n + i] == n)
			fill_row_dec(grid, n, i);
		i++;
	}
	return (ok);
}

static int	apply_peaks(int *grid, int n, int *clues)
{
	int	i;
	int	ok;
	int	idx;

	i = 0;
	ok = 1;
	while (i < n)
	{
		if (clues[i] == 1)
		{
			idx = 0 * n + i;
			if (!set_if_compat(grid, idx, n))
				return (0);
		}
		if (clues[n + i] == 1)
		{
			idx = (n - 1) * n + i;
			if (!set_if_compat(grid, idx, n))
				return (0);
		}
		if (clues[2 * n + i] == 1)
		{
			idx = i * n + 0;
			if (!set_if_compat(grid, idx, n))
				return (0);
		}
		if (clues[3 * n + i] == 1)
		{
			idx = i * n + (n - 1);
			if (!set_if_compat(grid, idx, n))
				return (0);
		}
		i++;
	}
	return (ok);
}

int	apply_obvious(int *grid, int n, int *clues)
{
	int	a;
	int	b;
	int	c;

	a = apply_full_cols(grid, n, clues);
	b = apply_full_rows(grid, n, clues);
	c = apply_peaks(grid, n, clues);
	if (!a || !b || !c)
		return (0);
	return (1);
}

static int	prune_partial(int *grid, int n, int pos, int *clues)
{
	int	row;
	int	col;
	int	ok;

	row = pos / n;
	col = pos % n;
	ok = check_row_partial(grid, n, row, clues);
	if (!ok)
		return (0);
	ok = check_col_partial(grid, n, col, clues);
	if (!ok)
		return (0);
	return (1);
}

int	solve(int *grid, int n, int pos, int *clues)
{
	int	next;
	int	val;
	int	ok;
	int	j;

	next = next_empty(grid, n, pos);
	if (next == -1)
	{
		j = 0;
		while (j < n)
		{
			if (!check_row_clues(grid, n, j, clues))
				return (0);
			if (!check_col_clues(grid, n, j, clues))
				return (0);
			j++;
		}
		return (1);
	}
	val = 1;
	while (val <= n)
	{
		if (is_safe(grid, n, next, val))
		{
			grid[next] = val;
			ok = prune_partial(grid, n, next, clues);
			if (ok)
			{
				if (solve(grid, n, next + 1, clues))
					return (1);
			}
			grid[next] = 0;
		}
		val++;
	}
	return (0);
}
