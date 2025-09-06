/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:53:47 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/03 17:55:43 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	is_lower_letter;

	is_lower_letter = 1;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			str++;
		else
		{
			is_lower_letter = 0;
			break ;
		}
	}
	return (is_lower_letter);
}
