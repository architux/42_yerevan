/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 04:28:27 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/18 23:06:42 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../.tests/test.h"

void	ft_putchar(char c);
void	ft_putnbr(int nb);

void	test(int number)
{
	printf("%i: $%s", number, COLOR_YELLOW);
	fflush(stdout);
	ft_putnbr(number);
	printf("%s$\n", COLOR_RESET);
}

int	main(void)
{
	test(-451);
	test(-42);
	test(0);
	test(42);
	test(451);
	return (0);
}
