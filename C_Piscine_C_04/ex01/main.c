/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:45:57 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/15 23:01:54 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../.tests/test.h"

void	ft_putstr(char *str);

int	main(void)
{
	char	*test_string;

	test_string = "tst str";
	printf("$%s", COLOR_YELLOW);
	fflush(stdout);
	ft_putstr(test_string);
	printf("%s$\n", COLOR_RESET);
}
