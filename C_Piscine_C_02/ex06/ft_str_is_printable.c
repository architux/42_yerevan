/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:09:27 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/11 17:33:51 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_printable(char c)
{
	int	printable_min_code_point;
	int	printable_max_code_point;

	printable_min_code_point = 32;
	printable_max_code_point = 126;
	return (c >= printable_min_code_point && c <= printable_max_code_point);
}

int	ft_str_is_printable(char *str)
{
	int	is_printable;

	is_printable = 1;
	while (*str)
	{
		if (ft_char_is_printable(*str))
			str++;
		else
			return (!is_printable);
	}
	return (is_printable);
}
