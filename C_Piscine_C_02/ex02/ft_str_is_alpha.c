/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:53:47 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/11 17:36:07 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_lower_alpha(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_char_is_upper_alpha(char c)
{
	return (c >= 'A' && c <= 'Z');
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
