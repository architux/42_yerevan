/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:40:54 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/09 22:12:17 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	char	str[] = "ABC";
	char	str_diff_upper[] = "AB";
	char	str_diff_lower[] = "ABZ";
	unsigned int	nums[] = {0, 1, 2, 3, 4};
	unsigned int	nums_size = sizeof(nums) / sizeof(nums[0]);
	unsigned int	i = 0;
	int		exit_code;

	printf("str: %s\n\n", str);
	while (i < nums_size)
	{
		printf("n: %i\n", nums[i]);

		printf("|- str diff is upper: %s\n", str_diff_upper);
		exit_code = ft_strncmp(str, str_diff_upper, nums[i]);
		printf("  |-       ft_strcmp: %i\n", exit_code);
		exit_code = strncmp(str, str_diff_upper, nums[i]);
		printf("  |-          strcmp: %i\n", exit_code);
		printf("\n");

		printf("|-      str is equal: %s\n", str);
		exit_code = ft_strncmp(str, str, nums[i]);
		printf("  |-       ft_strcmp: %i\n", exit_code);
		exit_code = strncmp(str, str, nums[i]);
		printf("  |-          strcmp: %i\n", exit_code);
		printf("\n");

		printf("|- str diff is lower: %s\n", str_diff_lower);
		exit_code = ft_strncmp(str, str_diff_lower, nums[i]);
		printf("  |-       ft_strcmp: %i\n", exit_code);
		exit_code = strncmp(str, str_diff_lower, nums[i]);
		printf("  |-          strcmp: %i\n", exit_code);

		if (i < nums_size - 1)
			printf("-----\n");
		i++;
	}

	return (0);
}
