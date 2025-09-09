/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:53:55 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/08 19:36:59 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str);

int	main(void)
{
	char	lower_str[] = "abcdefg";
	int		lower_result;
	char	non_lower_str[] = "aBcDeFg";
	int		non_lower_result;

	lower_result = ft_str_is_lowercase(lower_str);
	printf("    lower_str: %s > %i\n", lower_str, lower_result);
	non_lower_result = ft_str_is_lowercase(non_lower_str);
	printf("non_lower_str: %s > %i\n", non_lower_str, non_lower_result);
	return (0);
}
