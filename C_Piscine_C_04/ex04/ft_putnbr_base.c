/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 21:39:09 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/17 20:45:02 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#define ASCII_SIZE 256

#define CHAR_PRINTABLE_MIN_CODE_POINT 32
#define CHAR_PRINTABLE_MAX_CODE_POINT 126

#define CHAR_PLUS '+'
#define CHAR_MINUS '-'

#define CHECK_BASE_ERROR 0

int	ft_char_is_printable(char c)
{
	return (c >= CHAR_PRINTABLE_MIN_CODE_POINT
		&& c <= CHAR_PRINTABLE_MAX_CODE_POINT);
}

int	ft_char_is_sign(char c)
{
	return (c == CHAR_PLUS || c == CHAR_MINUS);
}

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

int	ft_check_base(char *base)
{
	unsigned char	duplicates_checker[ASCII_SIZE];
	int				i;

	i = 0;
	while (i < ASCII_SIZE)
	{
		duplicates_checker[i] = 0;
		i++;
	}
	if (!base || !base[0] || !base[1])
		return (CHECK_BASE_ERROR);
	i = 0;
	while (base[i])
	{
		if (ft_char_is_sign(base[i]))
			return (CHECK_BASE_ERROR);
		if (!ft_char_is_printable(base[i]))
			return (CHECK_BASE_ERROR);
		if (duplicates_checker[(unsigned char)base[i]])
			return (CHECK_BASE_ERROR);
		duplicates_checker[(unsigned char)base[i]] = 1;
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;
	int	nbr_final[ASCII_SIZE];
	int	i;

	base_len = ft_check_base(base);
	i = 0;
	if (base_len)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		else if (nbr == 0)
			ft_putchar(base[0]);
		while (nbr)
		{
			nbr_final[i] = nbr % base_len;
			nbr /= base_len;
			i++;
		}
		while (--i >= 0)
			ft_putchar(base[nbr_final[i]]);
	}
}
