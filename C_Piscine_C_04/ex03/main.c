/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 23:40:54 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/17 19:11:56 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../../.tests/test.h"

int	ft_atoi(char *str);

void	test(char *str, char *expected)
{
	printf("ft_atoi: $%s$ $%s%i%s$ <=> $%s%s%s$\n",
		str, COLOR_YELLOW, ft_atoi(str), COLOR_RESET,
		COLOR_GREEN, expected, COLOR_RESET);
	printf("   atoi: $%s$ $%s%i%s$ <=> $%s%s%s$\n",
		str, COLOR_YELLOW, ft_atoi(str), COLOR_RESET,
		COLOR_GREEN, expected, COLOR_RESET);
	printf("\n");
}

int	main(void)
{
	test(" ---+--+1234ab567", "-1234");
	test("+123z4ab567", "123");
	return (0);
}
