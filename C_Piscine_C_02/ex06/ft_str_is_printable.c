/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:09:27 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/03 22:18:32 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	printable_lower_index;
	int	printable_upper_index;
	int	is_printable;

	printable_lower_index = 32;
	printable_upper_index = 126;
	is_printable = 1;
	while (*str)
	{
		if (*str >= printable_lower_index && *str <= printable_upper_index)
			str++;
		else
		{
			is_printable = 0;
			break ;
		}
	}
	return (is_printable);
}
