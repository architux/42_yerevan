/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:13:56 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/11 17:28:49 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_char_is_printable(char c)
{
	int	printable_min_code_point;
	int	printable_max_code_point;

	printable_min_code_point = 32;
	printable_max_code_point = 126;
	return (c >= printable_min_code_point && c <= printable_max_code_point);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char			*hex_values;
	int				i;
	unsigned int	code_point;

	hex_values = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		if (!ft_char_is_printable(str[i]) || str[i] == '\\')
		{
			code_point = str[i];
			ft_putchar('\\');
			ft_putchar(hex_values[(code_point >> 4) & 0x0F]);
			ft_putchar(hex_values[code_point & 0x0F]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
