/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:44:34 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/03 17:53:07 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str);

int	main(void)
{
	char	numeric_str[] = "147258369";
	int	numeric_result;
	char	non_numeric_str[] = "147a258b369c";
	int	non_numeric_result;

	numeric_result = ft_str_is_numeric(numeric_str);
	printf("    numeric_str: %s > %i\n", numeric_str, numeric_result);
	non_numeric_result = ft_str_is_numeric(non_numeric_str);
	printf("non_numeric_str: %s > %i\n", non_numeric_str, non_numeric_result);
	return (0);
}
