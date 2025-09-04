/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:12:48 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/04 02:40:18 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(void)
{
	char	from_symbol;
	char	to_symbol;
	char	cur_symbol;

	from_symbol = '0';
	to_symbol = '9';
	cur_symbol = from_symbol;
	while (cur_symbol <= to_symbol)
	{
		ft_putchar(cur_symbol);
		cur_symbol++;
	}
}
