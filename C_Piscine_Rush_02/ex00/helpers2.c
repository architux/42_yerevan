/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:03:37 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/14 22:20:44 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_convert.h"

void	temp_func(t_mapping *mappings, int count, char *key, char *result)
{
	char	*temp;

	temp = find_mapping(mappings, count, key);
	if (temp)
		append_with_space(result, temp);
}

void	convert_tens_ones(int *arr, char *result,
		t_mapping *mappings, int count)
{
	char	key[4];

	if (arr[1] == 1)
	{
		key[0] = '1';
		key[1] = arr[2] + '0';
		key[2] = '\0';
		temp_func(mappings, count, key, result);
	}
	else
	{
		if (arr[1] > 0)
		{
			key[0] = arr[1] + '0';
			key[1] = '0';
			key[2] = '\0';
			temp_func(mappings, count, key, result);
		}
		if (arr[2] > 0)
		{
			key[0] = arr[2] + '0';
			key[1] = '\0';
			temp_func(mappings, count, key, result);
		}
	}
}

void	process_triplet(char *triplet, int *arr, char *result,
		t_mapping *mappings)
{
	char	*triplet_text;
	char	*scale_name;

	triplet_text = convert_triplet(triplet, mappings, arr[1]);
	if (triplet_text[0])
	{
		append_with_space(result, triplet_text);
		scale_name = find_scale_name(mappings, arr[1], arr[0]);
		if (scale_name && scale_name[0])
			append_with_space(result, scale_name);
	}
	free(triplet_text);
}

void	free_lines(char **lines, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (lines[i])
			free(lines[i]);
		i++;
	}
	free(lines);
}

void	free_mappings(t_mapping *mappings, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (mappings[i].key)
			free(mappings[i].key);
		if (mappings[i].value)
			free(mappings[i].value);
		i++;
	}
	free(mappings);
}
