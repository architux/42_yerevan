/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:53:55 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/03 17:58:40 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str);

int	main(void)
{
	char	upper_str[] = "ABCDEFG";
	int	upper_result;
	char	non_upper_str[] = "aBcDeFg";
	int	non_upper_result;

	upper_result = ft_str_is_uppercase(upper_str);
	printf("    upper_str: %s > %i\n", upper_str, upper_result);
	non_upper_result = ft_str_is_uppercase(non_upper_str);
	printf("non_upper_str: %s > %i\n", non_upper_str, non_upper_result);
	return (0);
}
