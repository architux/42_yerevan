/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:06:38 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/15 22:58:21 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../.tests/test.h"

int	ft_strlen(char *str);

int	main(void)
{
	char	*test_string;
	int		count;

	test_string = "tst str";
	count = ft_strlen(test_string);
	printf("String length of $%s%s%s$ is %i\n",
		COLOR_YELLOW, test_string, COLOR_RESET, count);
}
