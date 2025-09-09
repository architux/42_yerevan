/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:44:29 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/08 19:57:18 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_numeric(char c)
{
	int	is_numeric;

	if (c >= '0' && c <= '9')
		is_numeric = 1;
	else
		is_numeric = 0;
	return (is_numeric);
}

int	ft_str_is_numeric(char *str)
{
	int	is_numeric;

	is_numeric = 1;
	while (*str)
	{
		if (ft_char_is_numeric(*str))
			str++;
		else
			return (!is_numeric);
	}
	return (is_numeric);
}
