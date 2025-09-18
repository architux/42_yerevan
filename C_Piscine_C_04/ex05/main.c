/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:49:12 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/18 22:52:09 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../../.tests/test.h"

int ft_atoi_base(char *str, char *base);

void	test(char *str, char *base, char *expected)
{
	printf("$%s$, base $%s%s%s$: $%s%i%s$ <=> $%s%s%s$\n",
		str, COLOR_CYAN, base, COLOR_RESET,
		COLOR_YELLOW, ft_atoi_base(str, base), COLOR_RESET,
		COLOR_GREEN, expected, COLOR_RESET);
}

int	main(void)
{
	/* errors */
	test(" \r---+--+1234ab", "", "0, for base is empty");
	test(" \r---+--+1234ab", "0", "0, for base is one char long");
	test(" \r---+--+1234ab", "poneyvip", "0, for base has duplicates");
	printf("\n");
	/* binary */
	test(" \r---+--+111000011", "01", "-451");
	test("+101010z4ab567", "01", "42");
	printf("\n");
	/* decimal */
	test(" \r---+--+451", "0123456789", "451");
	test("+42z4ab567", "0123456789", "42");
	printf("\n");
	/* hexadecimal */
	test(" \r---+--+1C3p", "0123456789ABCDEF", "-451");
	test("+2Az4ab567", "0123456789ABCDEF", "42");
	printf("\n");
	/* octal */
	test(" \r---+--+fpeC3p", "poneyvif", "-451");
	test("+vnz4ab567", "poneyvif", "42");
	return (0);
}
