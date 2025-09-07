/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:01:41 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/07 14:07:52 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skyscrapers.h"

int	str_len(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		i++;
	}
	return (i);
}

void	write_char(char c)
{
	int	r;

	r = write(1, &c, 1);
	(void)r;
}

void	write_str(char *s)
{
	int	len;

	len = str_len(s);
	if (len > 0)
	{
		write(1, s, len);
	}
}

void	write_int(int n)
{
	int	t;
	int	m;

	if (n == 0)
	{
		write_char('0');
		return ;
	}
	if (n < 0)
	{
		write_char('-');
		n = -n;
	}
	m = 1;
	t = n;
	while (t >= 10)
	{
		m = m * 10;
		t = t / 10;
	}
	while (m > 0)
	{
		write_char((char)('0' + (n / m) % 10));
		m = m / 10;
	}
}

void	print_grid(int *grid, int n)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			idx = i * n + j;
			write_int(grid[idx]);
			if (j + 1 < n)
			{
				write_char(' ');
			}
			j++;
		}
		write_char('\n');
		i++;
	}
}
