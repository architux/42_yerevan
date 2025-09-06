/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:34:22 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/05 21:47:53 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src);

int	main(void)
{
	char	src[] = "123456";
	char	dest_longer_ft[] = "xxxxxxxxxxxx";
	char	dest_longer[] = "xxxxxxxxxxxx";
	char	dest_equal_fs[] = "xxxxxx";
	char	dest_equal[] = "xxxxxx";
	char	dest_shorter_fs[] = "xxx";
	char	dest_shorter[] = "xxx";

	printf("src: %s\n", src);

	printf("|-  dest_longer: %s\n", dest_longer);
	ft_strcpy(dest_longer_ft, src);
	printf("  |-  ft_strcpy: %s\n", dest_longer_ft);
	strcpy(dest_longer, src);
	printf("  |-     strcpy: %s\n", dest_longer);
	printf("\n");

	printf("|-   dest_equal: %s\n", dest_equal);
	ft_strcpy(dest_equal_fs, src);
	printf("  |-  ft_strcpy: %s\n", dest_equal_fs);
	strcpy(dest_equal, src);
	printf("  |-     strcpy: %s\n", dest_equal);
	printf("\n");

	printf("|- dest_shorter: %s\n", dest_shorter);
	ft_strcpy(dest_shorter_fs, src);
	printf("  |-  ft_strcpy: %s\n", dest_shorter_fs);
	ft_strcpy(dest_shorter, src);
	printf("  |-  ft_strcpy: %s\n", dest_shorter);
	return (0);
}
