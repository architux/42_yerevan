/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:53:55 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/03 17:43:22 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str);

int	main(void)
{
	char	alpha_str[] = "AbCdEfG";
	int	alpha_result;
	char	non_alpha_str[] = "aBc0eFg";
	int	non_alpha_result;

	alpha_result = ft_str_is_alpha(alpha_str);
	printf("    alpha_str: %s > %i\n", alpha_str, alpha_result);
	non_alpha_result = ft_str_is_alpha(non_alpha_str);
	printf("non_alpha_str: %s > %i\n", non_alpha_str, non_alpha_result);
	return (0);
}
