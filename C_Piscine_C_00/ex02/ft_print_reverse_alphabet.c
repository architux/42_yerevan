/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 22:29:15 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/04 02:39:20 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_reverse_alphabet(void)
{
	char	from_symbol;
	char	to_symbol;
	char	cur_symbol;

	from_symbol = 'z';
	to_symbol = 'a';
	cur_symbol = from_symbol;
	while (cur_symbol >= to_symbol)
	{
		ft_putchar(cur_symbol);
		cur_symbol--;
	}
}
