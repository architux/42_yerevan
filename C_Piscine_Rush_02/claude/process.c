/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:04:06 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/14 15:07:21 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_convert.h"

static int	g_last_error = 0;

int	get_last_error(void)
{
	return (g_last_error);
}

void	set_last_error(int error)
{
	g_last_error = error;
}

char	*process_conversion(char *dict_path, char *number)
{
	t_mapping	*mappings;
	int			count;
	char		*result;

	mappings = parse_dictionary(dict_path, &count);
	if (!mappings)
	{
		set_last_error(3);
		return (0);
	}
	if (!validate_dictionary(mappings, count))
	{
		free_mappings(mappings, count);
		set_last_error(3);
		return (0);
	}
	if (!can_convert_number(number, mappings, count))
	{
		free_mappings(mappings, count);
		set_last_error(4);
		return (0);
	}
	result = convert_number(number, mappings, count);
	free_mappings(mappings, count);
	return (result);
}
