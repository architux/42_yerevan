/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:53:47 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/08 19:54:41 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_lower_alpha(char c)
{
	int	is_lowercase;

	if (c >= 'a' && c <= 'z')
		is_lowercase = 1;
	else
		is_lowercase = 0;
	return (is_lowercase);
}

int	ft_str_is_lowercase(char *str)
{
	int	is_lowercase;

	is_lowercase = 1;
	while (*str)
	{
		if (ft_char_is_lower_alpha(*str))
			str++;
		else
			return (!is_lowercase);
	}
	return (is_lowercase);
}
