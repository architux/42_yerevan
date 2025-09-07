/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:40:19 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/07 22:37:20 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define SOLUTION_FOUND 1
#define NO_SOLUTION_FOUND 0

int	count_visible(int *line, int square_size)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	while (i < square_size)
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

int	check_clue_line(int *line, int clue_left, int clue_right, int square_size)
{
	int	*rev;
	int	i;
	int	val;

	rev = (int *)malloc(sizeof(int) * square_size);
	i = 0;
	while (i < square_size)
	{
		*(rev + i) = *(line + (square_size - 1 - i));
		i++;
	}
	val = (count_visible(line, square_size) == clue_left)
		&& (count_visible(rev, square_size) == clue_right);
	free(rev);
	return (val);
}

int	check_line_first_pass(int *line, int *grid, int *clues, int square_size)
{
	int	i;
	int	cursor;

	i = 0;
	while (i < square_size)
	{
		cursor = 0;
		while (cursor < square_size)
		{
			*(line + cursor) = *(grid + i * square_size + cursor);
			cursor++;
		}
		if (!check_clue_line(line, *(clues + 2 * square_size + i),
				*(clues + 3 * square_size + i), square_size))
		{
			free(line);
			return (NO_SOLUTION_FOUND);
		}
		i++;
	}
	return (SOLUTION_FOUND);
}

int	check_line_second_pass(int *line, int *grid, int *clues, int square_size)
{
	int	i;
	int	cursor;

	i = 0;
	while (i < square_size)
	{
		cursor = 0;
		while (cursor < square_size)
		{
			*(line + cursor) = *(grid + cursor * square_size + i);
			cursor++;
		}
		if (!check_clue_line(line, *(clues + i),
				*(clues + square_size + i), square_size))
		{
			free(line);
			return (NO_SOLUTION_FOUND);
		}
		i++;
	}
	return (SOLUTION_FOUND);
}

int	check_all_clues(int *grid, int *clues, int square_size)
{
	int	*line;
	int	check_result;

	line = (int *)malloc(sizeof(int) * square_size);
	check_result = check_line_first_pass(line, grid, clues, square_size);
	if (check_result == NO_SOLUTION_FOUND)
		return (NO_SOLUTION_FOUND);
	check_result = check_line_second_pass(line, grid, clues, square_size);
	if (check_result == NO_SOLUTION_FOUND)
		return (NO_SOLUTION_FOUND);
	free(line);
	return (SOLUTION_FOUND);
}
