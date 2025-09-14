/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:01:18 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/14 22:45:02 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_convert.h"

int	validate_number(char **number)
{
	char	*temp;
	char	*stripped;

	if (!check_number_format(*number))
		return (0);
	temp = *number;
	if (temp[0] == '+')
	{
		stripped = ft_strdup(temp + 1);
		free(temp);
		*number = stripped;
		temp = *number;
	}
	stripped = strip_leading_zeros(temp);
	if (!stripped)
		return (0);
	free(temp);
	*number = stripped;
	return (1);
}
