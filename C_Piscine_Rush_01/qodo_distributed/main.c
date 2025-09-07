/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 13:59:07 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/07 14:00:37 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscrapers.h"

static void	free_all(int *a, int *b)
{
	if (a)
	{
		free(a);
	}
	if (b)
	{
		free(b);
	}
}

static int	init_grid(int **grid, int n)
{
	int	i;
	int	t;

	*grid = (int *)malloc(sizeof(int) * n * n);
	if (!*grid)
	{
		return (0);
	}
	i = 0;
	t = n * n;
	while (i < t)
	{
		(*grid)[i] = 0;
		i = i + 1;
	}
	return (1);
}

static int	get_n_from_count(int count)
{
	int	n;
	int	ok;

	n = 0;
	ok = 0;
	while (n <= 9)
	{
		if (4 * n == count)
		{
			ok = 1;
			break ;
		}
		n++;
	}
	if (!ok)
	{
		return (0);
	}
	return (n);
}

int	main(int argc, char **argv)
{
	int	n;
	int	count;
	int	m;
	int	*clues;
	int	*grid;

	n = 0;
	count = 0;
	m = 0;
	clues = 0;
	grid = 0;
	if (argc != 2)
	{
		write_str("Error\n");
		return (1);
	}
	count = count_numbers(argv[1]);
	n = get_n_from_count(count);
	clues = (int *)malloc(sizeof(int) * 4 * n);
	if (!clues)
	{
		write_str("Error\n");
		return (1);
	}
	m = parse_numbers(argv[1], clues, 4 * n);
	if (m != 4 * n)
	{
		free_all(clues, 0);
		write_str("Error\n");
		return (1);
	}
	if (!validate_vals(clues, n))
	{
		free_all(clues, 0);
		write_str("Error\n");
		return (1);
	}
	if (!init_grid(&grid, n))
	{
		free_all(clues, 0);
		write_str("Error\n");
		return (1);
	}
	if (!apply_obvious(grid, n, clues))
	{
		free_all(clues, grid);
		write_str("Error\n");
		return (1);
	}
	if (!solve(grid, n, 0, clues))
	{
		free_all(clues, grid);
		write_str("Error\n");
		return (1);
	}
	print_grid(grid, n);
	free_all(clues, grid);
	return (0);
}
