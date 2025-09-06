/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:59:04 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/05 22:16:11 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

// int	ft_strlen(char *str);

// char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	char	src[] = "123456";
	unsigned int	nums[5] = {0, 3, 6, 12, 24};
	unsigned int	i = 0;

	printf("src: %s\n\n", src);
	while (i < 5)
	{
		// char	dest_longer_ft[] = "xxxxxxxxxxxx";
		// char	dest_equal_fs[] = "xxxxxx";
		// char	dest_shorter_fs[] = "xxx";
		char	dest_longer[] = "xxxxxxxxxxxx";
		char	dest_equal[] = "xxxxxx";
		char	dest_shorter[] = "xxx";

		printf("n: %i\n", nums[i]);

		printf("|-  dest_longer: %s\n", dest_longer);
		// ft_strncpy(dest_longer_ft, src, nums[i]);
		// printf("  |-  ft_strncpy: %s\n", dest_longer_ft);
		strncpy(dest_longer, src, nums[i]);
		printf("  |-    strncpy: %s\n", dest_longer);
		printf("\n");

		printf("|-   dest_equal: %s\n", dest_equal);
		// ft_strncpy(dest_equal_fs, src, nums[i]);
		// printf("  |-  ft_strncpy: %s\n", dest_equal_fs);
		strncpy(dest_equal, src, nums[i]);
		printf("  |-    strncpy: %s\n", dest_equal);
		printf("\n");

		printf("|- dest_shorter: %s\n", dest_shorter);
		// ft_strncpy(dest_shorter_fs, src, nums[i]);
		// printf("  |-  ft_strncpy: %s\n", dest_shorter_fs);
		strncpy(dest_shorter, src, nums[i]);
		printf("  |-    strncpy: %s\n", dest_shorter);

		if (i < 4)
			printf("-----\n");
		i++;
	}
	return (0);
}
