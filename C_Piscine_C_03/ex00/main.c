/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:07:30 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/15 21:05:50 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char	str[] = "ABA";
	char	str_diff_upper[] = "AB";
	char	str_diff_lower[] = "ABZ";
	int		ft_result;
	int		result;
	int		is_equal;

	char	*COLOR_GREEN = "\033[32m";
	char	*COLOR_YELLOW = "\033[33m";
	char	*COLOR_RED = "\033[31m";
	char	*COLOR_RESET = "\033[0m";

	printf("str: %s\n", str);

	printf("|- str diff is upper: %s\n", str_diff_upper);
	ft_result = ft_strcmp(str, str_diff_upper);
	printf("%s  |-           ft_strcmp: %i%s\n",
		COLOR_YELLOW, ft_result, COLOR_RESET);
	result = strcmp(str, str_diff_upper);
	printf("  |-              strcmp: %i\n", result);
	is_equal = ft_result == result;
	printf("%s  |- ft_strcmp == strcmp: %i%s\n",
		is_equal ? COLOR_GREEN : COLOR_RED, is_equal, COLOR_RESET);
	printf("\n");

	printf("|-      str is equal: %s\n", str);
	ft_result = ft_strcmp(str, str);
	printf("%s  |-           ft_strcmp: %i%s\n",
		COLOR_YELLOW, ft_result, COLOR_RESET);
	result = strcmp(str, str);
	printf("  |-              strcmp: %i\n", result);
	is_equal = ft_result == result;
	printf("%s  |- ft_strcmp == strcmp: %i%s\n",
		is_equal ? COLOR_GREEN : COLOR_RED, is_equal, COLOR_RESET);
	printf("\n");

	printf("|- str diff is lower: %s\n", str_diff_lower);
	ft_result = ft_strcmp(str, str_diff_lower);
	printf("%s  |-           ft_strcmp: %i%s\n",
		COLOR_YELLOW, ft_result, COLOR_RESET);
	result = strcmp(str, str_diff_lower);
	printf("  |-              strcmp: %i\n", result);
	is_equal = ft_result == result;
	printf("%s  |- ft_strcmp == strcmp: %i%s\n",
		is_equal ? COLOR_GREEN : COLOR_RED, is_equal, COLOR_RESET);

		return (0);
}
