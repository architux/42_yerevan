/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 05:27:46 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/08 05:27:51 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "io.h"
#include "parser.h"
#include "solver.h"

int	main(int argc, char **argv)
{
	int	n;
	int	m;
	int	ok;
	int	*vals;
	int	count;
	int	*grid;

	n = 0;
	m = 0;
	ok = 1;
	vals = 0;
	count = 0;
	grid = 0;
	if (argc < 2)
	{
		write_str("Error\n");
		return (1);
	}
	count = count_numbers(argv[1]);
	if (count % 4 != 0)
	{
		write_str("Error\n");
		return (1);
	}
	n = count / 4;
	vals = (int *)malloc(sizeof(int) * count);
	if (!vals)
	{
		write_str("Error\n");
		return (1);
	}
	m = parse_numbers(argv[1], vals, count);
	if (m != count)
	{
		free(vals);
		write_str("Error\n");
		return (1);
	}
	if (!validate_vals(vals, n))
	{
		free(vals);
		write_str("Error\n");
		return (1);
	}
	grid = (int *)malloc(sizeof(int) * n * n);
	if (!grid)
	{
		free(vals);
		write_str("Error\n");
		return (1);
	}
	m = 0;
	while (m < n * n)
	{
		grid[m] = 0;
		m = m + 1;
	}
	ok = apply_obvious(grid, n, vals);
	if (!ok)
	{
		free(grid);
		free(vals);
		write_str("Error\n");
		return (1);
	}
	ok = solve(grid, n, 0, vals);
	if (!ok)
	{
		free(grid);
		free(vals);
		write_str("Error\n");
		return (1);
	}
	print_grid(grid, n);
	free(grid);
	free(vals);
	return (0);
}
