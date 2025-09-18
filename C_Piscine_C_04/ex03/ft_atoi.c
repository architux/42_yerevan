/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 21:35:35 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/17 19:04:26 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_char_is_whitespace(char c)
{
	return (c == CHAR_SPACE
		|| c == CHAR_FORM_FEED
		|| c == CHAR_NEWLINE
		|| c == CHAR_CARRIAGE_RETURN
		|| c == CHAR_HORIZONTAL_TAB
		|| c == CHAR_VERTICAL_TAB);
}

int	ft_char_is_sign(char c)
{
	return (c == CHAR_PLUS || c == CHAR_MINUS);
}

int	ft_char_is_number(char c)
{
	return (c >= CHAR_ZERO && c <= CHAR_NINE);
}

int	ft_atoi(char *str)
{
	int		number;
	int		sign;
	int		i;

	number = 0;
	sign = 1;
	i = 0;
	while (ft_char_is_whitespace(str[i]))
		i++;
	while (ft_char_is_sign(str[i]))
	{
		if (str[i] == CHAR_MINUS)
			sign *= -1;
		i++;
	}
	while (ft_char_is_number(str[i]))
	{
		number *= DECIMAL_BASE;
		number += str[i] - CHAR_ZERO;
		i++;
	}
	return (number * sign);
}
