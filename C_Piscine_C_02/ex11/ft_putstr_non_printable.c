/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:13:56 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/09 19:02:05 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_char_is_printable(char c)
{
	int	printable_min_code_point;
	int	printable_max_code_point;
	int	is_printable;

	printable_min_code_point = 32;
	printable_max_code_point = 126;
	if (c >= printable_min_code_point && c <= printable_max_code_point)
		is_printable = 1;
	else
		is_printable = 0;
	return (is_printable);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char	*hex_values;
	int		i;

	hex_values = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		if (ft_char_is_printable(str[i]))
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			ft_putchar(hex_values[str[i] / 16]);
			ft_putchar(hex_values[str[i] % 16]);
		}
		i++;
	}
}
