/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:53:47 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/08 19:54:51 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_upper_alpha(char c)
{
	int	is_uppercase;

	if (c >= 'A' && c <= 'Z')
		is_uppercase = 1;
	else
		is_uppercase = 0;
	return (is_uppercase);
}

int	ft_str_is_uppercase(char *str)
{
	int	is_uppercase;

	is_uppercase = 1;
	while (*str)
	{
		if (ft_char_is_upper_alpha(*str))
			str++;
		else
			return (!is_uppercase);
	}
	return (is_uppercase);
}
