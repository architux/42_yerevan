/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:14:18 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/09 18:54:26 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putstr_non_printable(char *str);

int	main(void)
{
	char	*str;

	str = "Hello\nHow are\tyou?";
	printf("before: Hello\\nHow are\\tyou?\n");
	printf(" after: ");
	fflush(stdout);
	ft_putstr_non_printable(str);
	printf("\n");
	return (0);
}
