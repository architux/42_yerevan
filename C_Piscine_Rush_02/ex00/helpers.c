/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:03:15 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/14 15:37:13 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_convert.h"

char	*extract_substring(char *str, int start, int len)
{
	char	*result;
	int		i;

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

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t'
			&& line[i] != '\n' && line[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}

void	append_with_space(char *dest, char *src)
{
	int	len;
	int	i;

	len = ft_strlen(dest);
	if (len > 0 && dest[len - 1] != ' ')
	{
		dest[len] = ' ';
		len++;
	}
	i = 0;
	while (src[i])
	{
		dest[len] = src[i];
		len++;
		i++;
	}
	dest[len] = '\0';
}

char	*pad_number(char *number)
{
	int		len;
	int		pad_count;
	char	*result;
	int		i;
	int		j;

	len = ft_strlen(number);
	pad_count = (3 - (len % 3)) % 3;
	result = malloc(len + pad_count + 1);
	i = 0;
	while (i < pad_count)
	{
		result[i] = '0';
		i++;
	}
	j = 0;
	while (j < len)
	{
		result[i] = number[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}

void	extract_triplet(char *padded, int group_index, char *triplet)
{
	int	start;

	start = group_index * 3;
	triplet[0] = padded[start];
	triplet[1] = padded[start + 1];
	triplet[2] = padded[start + 2];
	triplet[3] = '\0';
}
