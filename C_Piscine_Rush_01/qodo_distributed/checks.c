/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 05:26:20 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/08 05:26:23 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checks.h"

int	visible_count(int *arr, int n)
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

static int	copy_row_to_buf(int *grid, int n, int row, int *buf)
{
	int	j;

	j = 0;
	while (j < n)
	{
		buf[j] = grid[row * n + j];
		j++;
	}
	return (0);
}

static int	copy_row_rev_to_buf(int *grid, int n, int row, int *buf)
{
	int	j;

	j = 0;
	while (j < n)
	{
		buf[j] = grid[row * n + (n - 1 - j)];
		j++;
	}
	return (0);
}

int	check_row_clues(int *grid, int n, int row, int *clues)
{
	int	*buf;
	int	leftv;
	int	rightv;
	int	cntl;
	int	cntr;

	buf = (int *)malloc(sizeof(int) * n);
	if (!buf)
		return (0);
	copy_row_to_buf(grid, n, row, buf);
	leftv = clues[2 * n + row];
	cntl = visible_count(buf, n);
	copy_row_rev_to_buf(grid, n, row, buf);
	rightv = clues[3 * n + row];
	cntr = visible_count(buf, n);
	free(buf);
	if (cntl != leftv)
		return (0);
	if (cntr != rightv)
		return (0);
	return (1);
}

static int	copy_col_to_buf(int *grid, int n, int col, int *buf)
{
	int	i;

	i = 0;
	while (i < n)
	{
		buf[i] = grid[i * n + col];
		i++;
	}
	return (0);
}

static int	copy_col_rev_to_buf(int *grid, int n, int col, int *buf)
{
	int	i;

	i = 0;
	while (i < n)
	{
		buf[i] = grid[(n - 1 - i) * n + col];
		i++;
	}
	return (0);
}

int	check_col_clues(int *grid, int n, int col, int *clues)
{
	int	*buf;
	int	topv;
	int	botv;
	int	cntt;
	int	cntb;

	buf = (int *)malloc(sizeof(int) * n);
	if (!buf)
		return (0);
	copy_col_to_buf(grid, n, col, buf);
	topv = clues[0 * n + col];
	cntt = visible_count(buf, n);
	copy_col_rev_to_buf(grid, n, col, buf);
	botv = clues[1 * n + col];
	cntb = visible_count(buf, n);
	free(buf);
	if (cntt != topv)
		return (0);
	if (cntb != botv)
		return (0);
	return (1);
}

int	is_safe(int *grid, int n, int pos, int val)
{
	int	row;
	int	col;
	int	k;
	int	idx;

	row = pos / n;
	col = pos % n;
	k = 0;
	while (k < n)
	{
		idx = row * n + k;
		if (grid[idx] == val)
			return (0);
		k++;
	}
	k = 0;
	while (k < n)
	{
		idx = k * n + col;
		if (grid[idx] == val)
			return (0);
		k++;
	}
	return (1);
}

int	next_empty(int *grid, int n, int start)
{
	int	p;

	p = start;
	while (p < n * n)
	{
		if (grid[p] == 0)
			return (p);
		p++;
	}
	return (-1);
}

int	check_final(int *grid, int n, int *clues)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (!check_row_clues(grid, n, i, clues))
			return (0);
		if (!check_col_clues(grid, n, i, clues))
			return (0);
		i++;
	}
	return (1);
}
