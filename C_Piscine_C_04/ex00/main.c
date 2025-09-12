/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:06:38 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/01 21:31:28 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str);

int	main(void)
{
	char	*test_string;
	int	count;

	test_string = "tst str";
	count = ft_strlen(test_string);
	printf("String length of '%s' is %i\n", test_string, count);
}
