/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 21:05:19 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/15 22:37:05 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../../.tests/test.h"

char	*ft_strstr(char *str, char *to_find);

void	test(char *haystack, char *needle)
{
	char	*ft_result;
	char	*result;

	ft_result = ft_strstr(haystack, needle);
	result = strstr(haystack, needle);
	printf("     haystack: $%s$\n", haystack);
	printf("%s    ft_strstr: $%s$ %s%s\n",
		COLOR_YELLOW, ft_strstr(haystack, needle), needle, COLOR_RESET);
	printf("       strstr: $%s$ %s\n\n", strstr(haystack, needle), needle);
}

int	main(void)
{
	test("ABCDEFG", "CD");
	test("ABCDEFG", "XYZ");
	return (0);
}
