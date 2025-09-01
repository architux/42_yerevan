/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:55:56 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/01 21:06:52 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

int	main(void)
{
	int	numbers[6];
	int	numbers_size;
	int	i;

	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4;
	numbers[4] = 5;
	numbers[5] = 6;
	numbers_size = sizeof(numbers) / sizeof(numbers[0]);
	i = 0;
	ft_rev_int_tab(numbers, numbers_size);
	printf("{");
	while (i < numbers_size)
	{
		printf("%i", numbers[i]);
		if (i < numbers_size - 1)
		{
			printf(", ");
		}
		i++;
	}
	printf("}\n");
}
