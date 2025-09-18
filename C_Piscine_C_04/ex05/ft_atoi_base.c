/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 21:39:34 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/18 23:00:09 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define ASCII_SIZE 256

#define CHAR_PRINTABLE_MIN_CODE_POINT 32
#define CHAR_PRINTABLE_MAX_CODE_POINT 126

#define CHAR_SPACE ' '
#define CHAR_FORM_FEED '\f'
#define CHAR_NEWLINE '\n'
#define CHAR_CARRIAGE_RETURN '\r'
#define CHAR_HORIZONTAL_TAB '\t'
#define CHAR_VERTICAL_TAB  '\v'

#define CHAR_PLUS '+'
#define CHAR_MINUS '-'

#define CHAR_ZERO '0'
#define CHAR_NINE '9'

#define DECIMAL_BASE 10

#define CHECK_BASE_ERROR 0

int	ft_char_is_whitespace(char c)
{
	return (c == CHAR_SPACE
		|| c == CHAR_FORM_FEED
		|| c == CHAR_NEWLINE
		|| c == CHAR_CARRIAGE_RETURN
		|| c == CHAR_HORIZONTAL_TAB
		|| c == CHAR_VERTICAL_TAB);
}

int	ft_char_is_printable(char c)
{
	return (c >= CHAR_PRINTABLE_MIN_CODE_POINT
		&& c <= CHAR_PRINTABLE_MAX_CODE_POINT);
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
		if (base[i] == CHAR_PLUS || base[i] == CHAR_MINUS)
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

int	ft_base_char_index(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		base_len;
	int		num;
	int		sign;
	int		i;

	base_len = ft_check_base(base);
	if (base_len < 2)
		return (0);
	num = 0;
	sign = 1;
	i = 0;
	while (ft_char_is_whitespace(str[i]))
		i++;
	while (str[i] == CHAR_PLUS || str[i] == CHAR_MINUS)
	{
		if (str[i] == CHAR_MINUS)
			sign *= -1;
		i++;
	}
	while (str[i] && ft_base_char_index(base, str[i]) != -1)
	{
		num = num * base_len + ft_base_char_index(base, str[i]);
		i++;
	}
	return (num * sign);
}
