/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:44:29 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/03 17:51:15 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	is_numeric;

	is_numeric = 1;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
		{
			is_numeric = 0;
			break ;
		}
	}
	return (is_numeric);
}
