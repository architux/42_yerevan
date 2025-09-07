/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:41:13 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/07 15:16:52 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		solve_grid(int *grid, int *clues, int n, int pos);
void	print_grid(int *grid, int n);

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
