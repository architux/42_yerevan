/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:40:40 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/07 15:07:36 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_row(int *grid, int n, int row, int val);
int	check_col(int *grid, int n, int col, int val);
int	check_all_clues(int *grid, int *clues, int n);

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
