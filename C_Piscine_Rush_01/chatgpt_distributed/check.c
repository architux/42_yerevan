/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:40:19 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/07 15:08:25 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_row(int *grid, int n, int row, int val)
{
	int	i;
	int	pos;

	i = 0;
	pos = row * n;
	while (i < n)
	{
		if (*(grid + pos + i) == val)
			return (0);
		i++;
	}
	return (1);
}

int	check_col(int *grid, int n, int col, int val)
{
	int	i;
	int	pos;

	i = 0;
	while (i < n)
	{
		pos = i * n + col;
		if (*(grid + pos) == val)
			return (0);
		i++;
	}
	return (1);
}

int	count_visible(int *line, int n)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < n)
	{
		if (*(line + i) > max)
		{
			max = *(line + i);
			count++;
		}
		i++;
	}
	return (count);
}

int	check_clue_line(int *line, int clue_left, int clue_right, int n)
{
	int	*rev;
	int	i;
	int	val;

	rev = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		*(rev + i) = *(line + (n - 1 - i));
		i++;
	}
	val = (count_visible(line, n) == clue_left)
		&& (count_visible(rev, n) == clue_right);
	free(rev);
	return (val);
}

int	check_all_clues(int *grid, int *clues, int n)
{
	int	*line;
	int	i;
	int	pos;

	line = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		pos = 0;
		while (pos < n)
		{
			*(line + pos) = *(grid + i * n + pos);
			pos++;
		}
		if (!check_clue_line(line, *(clues + 2 * n + i),
				*(clues + 3 * n + i), n))
		{
			free(line);
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < n)
	{
		pos = 0;
		while (pos < n)
		{
			*(line + pos) = *(grid + pos * n + i);
			pos++;
		}
		if (!check_clue_line(line, *(clues + i),
				*(clues + n + i), n))
		{
			free(line);
			return (0);
		}
		i++;
	}
	free(line);
	return (1);
}
