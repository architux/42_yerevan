/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamrazy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:16:11 by etamrazy          #+#    #+#             */
/*   Updated: 2025/08/30 16:12:08 by etamrazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	print_rect_symbol(int height, int width, int max_h, int max_w)
{
	if (height == 0)
	{
		if (width == 0)
			ft_putchar('A');
		else if (width == max_w)
			ft_putchar('C');
		else
			ft_putchar('B');
	}
	else if (height == max_h)
	{
		if (width == 0)
			ft_putchar('C');
		else if (width == max_w)
			ft_putchar('A');
		else
			ft_putchar('B');
	}
	else
	{
		if (width == 0 || width == max_w)
			ft_putchar('B');
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
