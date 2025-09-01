/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:37:00 by mvasilev          #+#    #+#             */
/*   Updated: 2025/08/31 18:07:52 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n);

void	ft_is_negative(int n)
{
	char	is_positive;
	char	is_negative;

	is_positive = 'P';
	is_negative = 'N';
	if (n >= 0)
		write(1, &is_positive, 1);
	else
		write(1, &is_negative, 1);
}
