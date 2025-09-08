/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 03:24:37 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/05 03:54:42 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_combination(int final_num, int cur_num_1, int cur_num_2)
{
	ft_putchar('0' + cur_num_1 / 10);
	ft_putchar('0' + cur_num_1 % 10);
	ft_putchar(' ');
	ft_putchar('0' + cur_num_2 / 10);
	ft_putchar('0' + cur_num_2 % 10);
	if (cur_num_1 != (final_num - 1) || cur_num_2 != final_num)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	final_num;
	int	cur_num_1;
	int	cur_num_2;

	final_num = 99;
	cur_num_1 = 0;
	while (cur_num_1 <= (final_num - 1))
	{
		cur_num_2 = cur_num_1 + 1;
		while (cur_num_2 <= final_num)
		{
			print_combination(final_num, cur_num_1, cur_num_2);
			cur_num_2++;
		}
		cur_num_1++;
	}
}
