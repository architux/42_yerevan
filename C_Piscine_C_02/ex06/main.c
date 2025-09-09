/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:09:30 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/09 17:29:19 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str);

int	main(void)
{
	char	printable_str[] = "abcdefg";
	int		printable_result;
	char	non_printable_str[] = "aBcD�eFg";
	int		non_printable_result;

	printable_result = ft_str_is_printable(printable_str);
	printf("    printable_str: %s > %i\n", printable_str, printable_result);
	non_printable_result = ft_str_is_printable(non_printable_str);
	printf("non_printable_str: %s > %i\n", non_printable_str, non_printable_result);
	return (0);
}
