/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:40:40 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/07 22:36:36 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INITIAL_GRID_VALUE 1
#define SOLUTION_FOUND 1
#define NO_SOLUTION_FOUND 0

int	check_all_clues(int *grid, int *clues, int square_size);

int	check_row(int *grid, int square_size, int row, int val)
{
	int	i;
	int	cursor;

	i = 0;
	cursor = row * square_size;
	while (i < square_size)
	{
		if (*(grid + cursor + i) == val)
			return (NO_SOLUTION_FOUND);
		i++;
	}
	return (SOLUTION_FOUND);
}

int	check_col(int *grid, int square_size, int col, int val)
{
	int	i;
	int	cursor;

	i = 0;
	while (i < square_size)
	{
		cursor = i * square_size + col;
		if (*(grid + cursor) == val)
			return (NO_SOLUTION_FOUND);
		i++;
	}
	return (SOLUTION_FOUND);
}

int	solve_grid(int *grid, int *clues, int square_size, int cursor)
{
	int	row;
	int	col;
	int	val;

	if (cursor == square_size * square_size)
		return (check_all_clues(grid, clues, square_size));
	row = cursor / square_size;
	col = cursor % square_size;
	val = INITIAL_GRID_VALUE;
	while (val <= square_size)
	{
		if (check_row(grid, square_size, row, val)
			&& check_col(grid, square_size, col, val))
		{
			*(grid + cursor) = val;
			if (solve_grid(grid, clues, square_size, cursor + 1))
				return (SOLUTION_FOUND);
			*(grid + cursor) = 0;
		}
		val++;
	}
	return (NO_SOLUTION_FOUND);
}
