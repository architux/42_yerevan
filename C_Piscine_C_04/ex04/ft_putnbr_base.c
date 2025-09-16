/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 21:39:09 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/16 23:00:04 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#define CHAR_PRINTABLE_MIN_CODE_POINT 32
#define CHAR_PRINTABLE_MAX_CODE_POINT 126

#define CHAR_PLUS '+'
#define CHAR_MINUS '-'

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
	int	*duplicates_check;
	int	i;

	duplicates_check = calloc(256, sizeof(int));
	if (duplicates_check == NULL)
		return (0);
	if (!base || !base[1])
		return (0);
	i = 0;
	while (base[i])
	{
		if (ft_char_is_sign(base[i]))
			return (0);
		if (!ft_char_is_printable(base[i]))
			return (0);
		if (duplicates_check[(unsigned char)base[i]] > 0)
		{
			free(duplicates_check);
			return (0);
		}
		else
			duplicates_check[(unsigned char)base[i]]++;
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_type;
	int	nbr_final[100];
	int	i;

	base_type = ft_check_base(base);
	i = 0;
	if (base_type)
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
			nbr_final[i] = nbr % base_type;
			nbr /= base_type;
			i++;
		}
		while (--i >= 0)
			ft_putchar(base[nbr_final[i]]);
	}
}
