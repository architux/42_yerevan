/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:01:18 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/14 15:37:56 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_convert.h"

char	*trim_whitespace(char *str)
{
	char	*result;
	int		start;
	int		end;
	int		i;
	int		j;

	start = 0;
	while (str[start] == ' ' || str[start] == '\t'
		|| str[start] == '\n' || str[start] == '\r')
		start++;
	end = ft_strlen(str) - 1;
	while (end >= start && (str[end] == ' ' || str[end] == '\t'
			|| str[end] == '\n' || str[end] == '\r'))
		end--;
	result = malloc(end - start + 2);
	if (!result)
		return (0);
	i = start;
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
