/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 05:21:11 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/08 06:16:49 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "io.h"

int	str_len(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	write_str(char *s)
{
	int	len;

	len = str_len(s);
	if (len > 0)
		write(1, s, len);
}

void	write_char(char c)
{
	int	dummy;

	dummy = write(1, &c, 1);
	(void)dummy;
}

void	write_int(int n)
{
	char	buf[12];
	int		idx;
	int		t;

	idx = 0;
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
	while (n > 0)
	{
		t = n % 10;
		buf[idx] = (char)('0' + t);
		idx++;
		n = n / 10;
	}
	while (idx > 0)
	{
		idx--;
		write_char(buf[idx]);
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
				write_char(' ');
			j++;
		}
		write_char('\n');
		i++;
	}
}
