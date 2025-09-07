/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 02:36:09 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/07 15:18:54 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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
			count = count + 1;
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

int	solve_grid(int *grid, int *clues, int n, int pos)
{
	int	row;
	int	col;
	int	val;

	if (pos == n * n)
		return (check_all_clues(grid, clues, n));
	row = pos / n;
	col = pos % n;
	val = 1;
	while (val <= n)
	{
		if (check_row(grid, n, row, val)
			&& check_col(grid, n, col, val))
		{
			*(grid + pos) = val;
			if (solve_grid(grid, clues, n, pos + 1))
				return (1);
			*(grid + pos) = 0;
		}
		val++;
	}
	return (0);
}

void	print_grid(int *grid, int n)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			c = *(grid + i * n + j) + '0';
			write(1, &c, 1);
			if (j < n - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	n;
	int	*grid;
	int	*clues;
	int	i;
	int	count;

	if (argc < 2)
	{
		write(2, "Input error\n", 12);
		return (1);
	}
	count = 0;
	i = 0;
	while (*(argv[1] + i) != '\0')
	{
		if (*(argv[1] + i) >= '0' && *(argv[1] + i) <= '9')
			count++;
		i++;
	}
	n = count / 4;
	grid = (int *)malloc(sizeof(int) * n * n);
	clues = (int *)malloc(sizeof(int) * n * 4);
	i = 0;
	while (i < n * n)
	{
		*(grid + i) = 0;
		i++;
	}
	i = 0;
	count = 0;
	while (*(argv[1] + i) != '\0')
	{
		if (*(argv[1] + i) >= '0' && *(argv[1] + i) <= '9')
		{
			*(clues + count) = *(argv[1] + i) - '0';
			count++;
		}
		i++;
	}
	if (solve_grid(grid, clues, n, 0))
		print_grid(grid, n);
	else
		write(2, "No solution found\n", 18);
	free(grid);
	free(clues);
	return (0);
}
