/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 22:19:53 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/07 23:14:56 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_grid(int *grid, int square_size)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < square_size)
	{
		j = 0;
		while (j < square_size)
		{
			c = *(grid + i * square_size + j) + '0';
			write(STDOUT_FILENO, &c, 1);
			if (j < square_size - 1)
				write(STDOUT_FILENO, " ", 1);
			j++;
		}
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
