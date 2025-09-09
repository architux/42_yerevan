/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:53:47 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/08 20:14:05 by mvasilev         ###   ########.fr       */
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

int	ft_char_is_upper_alpha(char c)
{
	int	is_uppercase;

	if (c >= 'A' && c <= 'Z')
		is_uppercase = 1;
	else
		is_uppercase = 0;
	return (is_uppercase);
}

int	ft_char_is_alpha(char c)
{
	return (ft_char_is_lower_alpha(c) || ft_char_is_upper_alpha(c));
}

int	ft_str_is_alpha(char *str)
{
	int	is_alpha;

	is_alpha = 1;
	while (*str)
	{
		if (ft_char_is_alpha(*str))
			str++;
		else
			return (!is_alpha);
	}
	return (is_alpha);
}
