/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:21:22 by etamrazy          #+#    #+#             */
/*   Updated: 2025/09/04 17:09:15 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_rect_symbol(int height, int width, int max_h, int max_w)
{
	if (height == 0 || height == max_h)
	{
		if (width == 0 || width == max_w)
			ft_putchar('o');
		else
			ft_putchar('-');
	}
	else
	{
		if (width == 0 || width == max_w)
			ft_putchar('|');
		else
			ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	width;
	int	height;

	if (x <= 0 || y <= 0)
	{
		write(2, "x and y must be positive integers more than 0\n", 46);
		return ;
	}
	height = 0;
	while (height < y)
	{
		width = 0;
		while (width < x)
		{
			print_rect_symbol(height, width, y - 1, x - 1);
			width++;
		}
		ft_putchar('\n');
		height++;
	}
}
