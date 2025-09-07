/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:06:01 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/07 14:07:18 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscrapers.h"

static int	visible_count(int *arr, int n)
{
	int	i;
	int	maxh;
	int	cnt;

	i = 0;
	maxh = 0;
	cnt = 0;
	while (i < n)
	{
		if (arr[i] > maxh)
		{
			maxh = arr[i];
			cnt++;
		}
		i++;
	}
	return (cnt);
}

int	row_complete(int *grid, int n, int row)
{
	int	j;
	int	idx;

	j = 0;
	while (j < n)
	{
		idx = row * n + j;
		if (grid[idx] == 0)
			return (0);
		j++;
	}
	return (1);
}

int	col_complete(int *grid, int n, int col)
{
	int	i;
	int	idx;

	i = 0;
	while (i < n)
	{
		idx = i * n + col;
		if (grid[idx] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_row_clues(int *grid, int n, int row, int *clues)
{
	int	j;
	int	cntl;
	int	cntr;
	int	*rev;

	if (!row_complete(grid, n, row))
		return (1);
	cntl = visible_count(&grid[row * n], n);
	rev = (int *)malloc(sizeof(int) * n);
	if (!rev)
		return (0);
	j = 0;
	while (j < n)
	{
		rev[j] = grid[row * n + (n - 1 - j)];
		j++;
	}
	cntr = visible_count(rev, n);
	free(rev);
	if (cntl != clues[2 * n + row])
		return (0);
	if (cntr != clues[3 * n + row])
		return (0);
	return (1);
}

int	check_col_clues(int *grid, int n, int col, int *clues)
{
	int	i;
	int	cntt;
	int	cntb;
	int	*buf;

	if (!col_complete(grid, n, col))
		return (1);
	buf = (int *)malloc(sizeof(int) * n);
	if (!buf)
		return (0);
	i = 0;
	while (i < n)
	{
		buf[i] = grid[i * n + col];
		i++;
	}
	cntt = visible_count(buf, n);
	i = 0;
	while (i < n)
	{
		buf[i] = grid[(n - 1 - i) * n + col];
		i++;
	}
	cntb = visible_count(buf, n);
	free(buf);
	if (cntt != clues[col])
		return (0);
	if (cntb != clues[n + col])
		return (0);
	return (1);
}

int	check_row_partial(int *grid, int n, int row, int *clues)
{
	int	j;
	int	seen;
	int	maxh;

	j = 0;
	seen = 0;
	maxh = 0;
	while (j < n)
	{
		if (grid[row * n + j] != 0 && grid[row * n + j] > maxh)
		{
			maxh = grid[row * n + j];
			seen++;
		}
		j++;
	}
	if (seen > clues[2 * n + row])
		return (0);
	return (1);
}

int	check_col_partial(int *grid, int n, int col, int *clues)
{
	int	i;
	int	seen;
	int	maxh;

	i = 0;
	seen = 0;
	maxh = 0;
	while (i < n)
	{
		if (grid[i * n + col] != 0 && grid[i * n + col] > maxh)
		{
			maxh = grid[i * n + col];
			seen++;
		}
		i++;
	}
	if (seen > clues[col])
		return (0);
	return (1);
}

int	is_safe(int *grid, int n, int pos, int val)
{
	int	row;
	int	col;
	int	k;

	row = pos / n;
	col = pos % n;
	k = 0;
	while (k < n)
	{
		if (grid[row * n + k] == val)
			return (0);
		if (grid[k * n + col] == val)
			return (0);
		k++;
	}
	return (1);
}

int	next_empty(int *grid, int n, int start)
{
	int	p;
	int	lim;

	p = start;
	lim = n * n;
	while (p < lim)
	{
		if (grid[p] == 0)
			return (p);
		p++;
	}
	return (-1);
}
