/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_str_is_alpha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:53:47 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/03 17:50:43 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	is_letter;

	is_letter = 1;
	while (*str)
	{
		if ((*str >= 'a' && *str <= 'z')
			|| (*str >= 'A' && *str <= 'Z'))
			str++;
		else
		{
			is_letter = 0;
			break ;
		}
	}
	return (is_letter);
}
