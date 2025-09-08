/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 01:31:28 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/05 04:24:50 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_combination(int cur_1, int cur_2, int cur_3)
{
	ft_putchar('0' + cur_1);
	ft_putchar('0' + cur_2);
	ft_putchar('0' + cur_3);
	if (cur_1 != 7 || cur_2 != 8 || cur_3 != 9)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int	cur_1;
	int	cur_2;
	int	cur_3;

	cur_1 = 0;
	while (cur_1 <= 7)
	{
		cur_2 = cur_1 + 1;
		while (cur_2 <= 8)
		{
			cur_3 = cur_2 + 1;
			while (cur_3 <= 9)
			{
				print_combination(cur_1, cur_2, cur_3);
				cur_3++;
			}
			cur_2++;
		}
		cur_1++;
	}
}
