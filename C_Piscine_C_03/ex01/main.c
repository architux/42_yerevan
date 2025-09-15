/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:40:54 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/15 20:34:06 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	char			str[] = "ABC";
	char			str_diff_upper[] = "AB";
	char			str_diff_lower[] = "ABZ";
	unsigned int	nums[] = {-3, 0, 1, 2, 3, 4};
	unsigned int	nums_size = sizeof(nums) / sizeof(nums[0]);
	unsigned int	i = 0;
	int				ft_result;
	int				result;
	unsigned int	is_equal;

	char			*COLOR_GREEN = "\033[32m";
	char			*COLOR_YELLOW = "\033[33m";
	char			*COLOR_RED = "\033[31m";
	char			*COLOR_RESET = "\033[0m";

	printf("str: %s\n\n", str);
	while (i < nums_size)
	{
		printf("n: %i\n", nums[i]);

		printf("|-     str diff is upper: %s\n", str_diff_upper);
		ft_result = ft_strncmp(str, str_diff_upper, nums[i]);
		printf("%s  |-           ft_strcmp: %i%s\n",
			COLOR_YELLOW, ft_result, COLOR_RESET);
		result = strncmp(str, str_diff_upper, nums[i]);
		printf("  |-              strcmp: %i\n", result);
		is_equal = ft_result == result;
		printf("%s  |- ft_strcmp == strcmp: %i%s\n",
			is_equal ? COLOR_GREEN : COLOR_RED, is_equal, COLOR_RESET);
		printf("\n");

		printf("|-          str is equal: %s\n", str);
		ft_result = ft_strncmp(str, str, nums[i]);
		printf("%s  |-           ft_strcmp: %i%s\n",
			COLOR_YELLOW, ft_result, COLOR_RESET);
		result = strncmp(str, str, nums[i]);
		printf("  |-              strcmp: %i\n", result);
		is_equal = ft_result == result;
		printf("%s  |- ft_strcmp == strcmp: %i%s\n",
			is_equal ? COLOR_GREEN : COLOR_RED, is_equal, COLOR_RESET);
		printf("\n");

		printf("|-     str diff is lower: %s\n", str_diff_lower);
		ft_result = ft_strncmp(str, str_diff_lower, nums[i]);
		printf("%s  |-           ft_strcmp: %i%s\n",
			COLOR_YELLOW, ft_result, COLOR_RESET);
		result = strncmp(str, str_diff_lower, nums[i]);
		printf("  |-              strcmp: %i\n", result);
		is_equal = ft_result == result;
		printf("%s  |- ft_strcmp == strcmp: %i%s\n",
			is_equal ? COLOR_GREEN : COLOR_RED, is_equal, COLOR_RESET);

		if (i < nums_size - 1)
			printf("-----\n");
		i++;
	}

	return (0);
}
