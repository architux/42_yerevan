/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:53:47 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/03 17:59:15 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	is_upper_letter;

	is_upper_letter = 1;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			str++;
		else
		{
			is_upper_letter = 0;
			break ;
		}
	}
	return (is_upper_letter);
}
