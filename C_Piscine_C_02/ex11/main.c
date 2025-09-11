/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:14:18 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/11 17:23:07 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putstr_non_printable(char *str);

int	main(void)
{
	char	str[] = "\" Hello \n How \\ are \t \xFF you? ÿ '";

	printf("before: $\" Hello \\n How \\ are \\t \\xFF you? ÿ '$\n");
	printf(" after: $");
	fflush(stdout);
	ft_putstr_non_printable(str);
	printf("$\n");
	return (0);
}
