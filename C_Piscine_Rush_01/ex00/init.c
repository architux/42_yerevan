/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:13:17 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/07 23:19:58 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define SQUARE_SIDES_COUNT 4
#define CHAR_0 '0'
#define CHAR_9 '9'

int	count_clues(char **argv)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (*(argv[1] + i))
	{
		if (*(argv[1] + i) >= CHAR_0 && *(argv[1] + i) <= CHAR_9)
			count++;
		i++;
	}
	return (count);
}

int	*parse_clues(char **argv, int square_size)
{
	int	*clues;
	int	count;
	int	i;

	clues = (int *)malloc(sizeof(int) * square_size * SQUARE_SIDES_COUNT);
	count = 0;
	i = 0;
	while (*(argv[1] + i))
	{
		if (*(argv[1] + i) >= CHAR_0 && *(argv[1] + i) <= CHAR_9)
		{
			*(clues + count) = *(argv[1] + i) - CHAR_0;
			count++;
		}
		i++;
	}
	return (clues);
}

int	*init_grid(int square_size)
{
	int	*grid;
	int	i;

	grid = (int *)malloc(sizeof(int) * square_size * square_size);
	i = 0;
	while (i < square_size * square_size)
	{
		*(grid + i) = 0;
		i++;
	}
	return (grid);
}
