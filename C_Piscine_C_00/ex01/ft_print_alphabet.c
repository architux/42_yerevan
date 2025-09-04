/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 22:26:09 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/04 02:38:39 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_alphabet(void)
{
	char	from_symbol;
	char	to_symbol;
	char	cur_symbol;

	from_symbol = 'a';
	to_symbol = 'z';
	cur_symbol = from_symbol;
	while (cur_symbol <= to_symbol)
	{
		ft_putchar(cur_symbol);
		cur_symbol++;
	}
}
