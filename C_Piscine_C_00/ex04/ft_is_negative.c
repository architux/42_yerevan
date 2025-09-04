/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:37:00 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/04 02:31:45 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int n)
{
	char	is_positive;
	char	is_negative;

	is_positive = 'P';
	is_negative = 'N';
	if (n >= 0)
		ft_putchar(is_positive);
	else
		ft_putchar(is_negative);
}
