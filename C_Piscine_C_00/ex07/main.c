/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 04:28:27 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/05 04:32:49 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putchar(char c);

void	ft_putnbr(int nb);

int	main(void)
{
	int	number;

	number = -42;
	ft_putnbr(number);
	ft_putchar('\n');
	number = 0;
	ft_putnbr(number);
	ft_putchar('\n');
	number = 42;
	ft_putnbr(number);
	ft_putchar('\n');
	number = 642;
	ft_putnbr(number);
	ft_putchar('\n');
	return (0);
}
