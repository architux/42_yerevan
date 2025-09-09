/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:22:09 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/08 20:38:20 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);

int	main(void)
{
	char	src[7] = "123456";
	unsigned int	nums[4] = {0, 4, 7, 19};
	unsigned int	nums_size = sizeof(nums) / sizeof(nums[0]);
	unsigned int	i = 0;

	printf("src: %s\n\n", src);
	while (i < nums_size)
	{
		char	dest_longer_ft[19] = "xxxxxxxxxxxxxxxxxx";
		char	dest_longer[19] = "xxxxxxxxxxxxxxxxxx";
		char	dest_equal_fs[7] = "xxxxxx";
		char	dest_equal[7] = "xxxxxx";
		char	dest_shorter_fs[4] = "xxx";
		char	dest_shorter[4] = "xxx";

		printf("n: %i\n", nums[i]);

		printf("|-  dest_longer: .%s.\n", dest_longer);
		ft_strlcpy(dest_longer_ft, src, nums[i]);
		printf("  |- ft_strlcpy: .%s.\n", dest_longer_ft);
		// strlcpy(dest_longer, src, nums[i]);
		// printf("  |-    strlcpy: .%s.\n", dest_longer);
		printf("\n");

		printf("|-   dest_equal: .%s.\n", dest_equal);
		ft_strlcpy(dest_equal_fs, src, nums[i]);
		printf("  |- ft_strlcpy: .%s.\n", dest_equal_fs);
		// strlcpy(dest_equal, src, nums[i]);
		// printf("  |-    strlcpy: .%s.\n", dest_equal);
		printf("\n");

		printf("|- dest_shorter: .%s.\n", dest_shorter);
		ft_strlcpy(dest_shorter_fs, src, nums[i]);
		printf("  |- ft_strlcpy: .%s.\n", dest_shorter_fs);
		// strlcpy(dest_shorter, src, nums[i]);
		// printf("  |-    strlcpy: .%s.\n", dest_shorter);

		if (i < nums_size - 1)
			printf("-----\n");
		i++;
	}
	return (0);
}
