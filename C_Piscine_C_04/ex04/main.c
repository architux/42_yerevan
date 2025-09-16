/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:47:16 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/16 22:55:16 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../.tests/test.h"

void	ft_putnbr_base(int nbr, char *base);

void	test(int number, char *base, char *expected)
{
	printf("%4i, base $%s%s%s$: $%s", number, COLOR_CYAN, base, COLOR_RESET, COLOR_YELLOW);
	fflush(stdout);
	ft_putnbr_base(number, base);
	printf("%s$ <=> $%s%s%s$\n",
		COLOR_RESET, COLOR_GREEN, expected, COLOR_RESET);
}

int	main(void)
{
	test(0, "", "nothing, for base is empty");
	test(42, "0", "nothing, for base is one char long");
	test(451, "poneyvip", "nothing, for base has duplicates");
	printf("\n");
	test(-451, "01", "111000011");
	test(-42, "01", "-101010");
	test(0, "01", "0");
	test(42, "01", "101010");
	test(451, "01", "111000011");
	printf("\n");
	test(-451, "0123456789", "-451");
	test(-42, "0123456789", "-42");
	test(0, "0123456789", "0");
	test(42, "0123456789", "42");
	test(451, "0123456789", "451");
	printf("\n");
	test(-451, "0123456789ABCDEF", "-1C3");
	test(-42, "0123456789ABCDEF", "-2A");
	test(0, "0123456789ABCDEF", "0");
	test(42, "0123456789ABCDEF", "2A");
	test(451, "0123456789ABCDEF", "1C3");
	printf("\n");
	test(-451, "poneyvif", "-fpe (703)");
	test(-42, "poneyvif", "-vn (52)");
	test(0, "poneyvif", "p (0)");
	test(42, "poneyvif", "vn (52)");
	test(451, "poneyvif", "fpe (703)");
	return (0);
}
