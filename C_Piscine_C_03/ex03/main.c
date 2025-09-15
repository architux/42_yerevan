/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:40:54 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/15 21:40:18 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	main(void)
{
	char			src[] = "123456";
	unsigned int	nums[] = {0, 3, 6, 18};
	unsigned int	nums_size = sizeof(nums) / sizeof(nums[0]);
	unsigned int	i = 0;

	// char			*COLOR_GREEN = "\033[32m";
	char			*COLOR_YELLOW = "\033[33m";
	// char			*COLOR_RED = "\033[31m";
	char			*COLOR_RESET = "\033[0m";

	printf("src: %s\n\n", src);
	while (i < nums_size)
	{
		char	dest_longer_ft[] = "xxxxxxxxxxxxxxxxxx";
		char	dest_longer[] = "xxxxxxxxxxxxxxxxxx";
		char	dest_equal_fs[] = "xxxxxx";
		char	dest_equal[] = "xxxxxx";
		char	dest_shorter_fs[] = "xxx";
		char	dest_shorter[] = "xxx";

		printf("n: %i\n", nums[i]);

		printf("|-  dest_longer: $%s$\n", dest_longer);
		ft_strncat(dest_longer_ft, src, nums[i]);
		printf("%s  |- ft_strncpy: $%s$%s\n", COLOR_YELLOW, dest_longer_ft, COLOR_RESET);
		strncat(dest_longer, src, nums[i]);
		printf("  |-    strncpy: $%s$\n", dest_longer);
		printf("\n");

		printf("|-   dest_equal: $%s$\n", dest_equal);
		ft_strncat(dest_equal_fs, src, nums[i]);
		printf("%s  |- ft_strncpy: $%s$%s\n", COLOR_YELLOW, dest_equal_fs, COLOR_RESET);
		strncat(dest_equal, src, nums[i]);
		printf("  |-    strncpy: $%s$\n", dest_equal);
		printf("\n");

		printf("|- dest_shorter: $%s$\n", dest_shorter);
		ft_strncat(dest_shorter_fs, src, nums[i]);
		printf("%s  |- ft_strncpy: $%s$%s\n", COLOR_YELLOW, dest_shorter_fs, COLOR_RESET);
		strncat(dest_shorter, src, nums[i]);
		printf("  |-    strncpy: $%s$\n", dest_shorter);

		if (i < nums_size - 1)
			printf("-----\n");
		i++;
	}
	return (0);
}
