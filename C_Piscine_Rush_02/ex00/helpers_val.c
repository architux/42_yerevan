/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:43:36 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/14 22:45:36 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_convert.h"

char	*get_result(char *result, int end, int i, char *str)
{
	int	j;

	if (!result)
		return (0);
	j = 0;
	while (i <= end)
	{
		result[j] = str[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}

char	*trim_whitespace(char *str)
{
	char	*result;
	int		start;
	int		end;
	int		i;

	start = 0;
	while (str[start] == ' ' || str[start] == '\t'
		|| str[start] == '\n' || str[start] == '\r')
		start++;
	end = ft_strlen(str) - 1;
	while (end >= start && (str[end] == ' ' || str[end] == '\t'
			|| str[end] == '\n' || str[end] == '\r'))
		end--;
	result = malloc(end - start + 2);
	i = start;
	return (get_result(result, end, i, str));
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*strip_leading_zeros(char *str)
{
	char	*result;
	int		start;
	int		len;
	int		i;

	start = 0;
	while (str[start] == '0' && str[start + 1])
		start++;
	len = ft_strlen(str) - start;
	result = malloc(len + 1);
	if (!result)
		return (0);
	i = 0;
	while (i < len)
	{
		result[i] = str[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	check_number_format(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	if (str[0] == '-')
		return (0);
	i = 0;
	if (str[0] == '+')
		i = 1;
	while (str[i])
	{
		if (!is_digit(str[i]))
		{
			if (str[i] == '.' || str[i] == ',')
				return (0);
			return (0);
		}
		i++;
	}
	return (1);
}
