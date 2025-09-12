/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:07:30 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/09 22:21:24 by mvasilev         ###   ########.fr       */
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
	int		exit_code;

	printf("str: %s\n", str);

	printf("|- str diff is upper: %s\n", str_diff_upper);
	exit_code = ft_strcmp(str, str_diff_upper);
	printf("  |-       ft_strcmp: %i\n", exit_code);
	exit_code = strcmp(str, str_diff_upper);
	printf("  |-          strcmp: %i\n", exit_code);
	printf("\n");

	printf("|-      str is equal: %s\n", str);
	exit_code = ft_strcmp(str, str);
	printf("  |-       ft_strcmp: %i\n", exit_code);
	exit_code = strcmp(str, str);
	printf("  |-          strcmp: %i\n", exit_code);
	printf("\n");

	printf("|- str diff is lower: %s\n", str_diff_lower);
	exit_code = ft_strcmp(str, str_diff_lower);
	printf("  |-       ft_strcmp: %i\n", exit_code);
	exit_code = strcmp(str, str_diff_lower);
	printf("  |-          strcmp: %i\n", exit_code);

	return (0);
}
