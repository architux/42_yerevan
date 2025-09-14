/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:03:37 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/14 15:37:32 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_convert.h"

void	convert_tens_ones(int t, int o, char *result,
		t_mapping *mappings, int count)
{
	char	key[4];
	char	*temp;

	if (t == 1)
	{
		key[0] = '1';
		key[1] = o + '0';
		key[2] = '\0';
		temp = find_mapping(mappings, count, key);
		if (temp)
			append_with_space(result, temp);
	}
	else
	{
		if (t > 0)
		{
			key[0] = t + '0';
			key[1] = '0';
			key[2] = '\0';
			temp = find_mapping(mappings, count, key);
			if (temp)
				append_with_space(result, temp);
		}
		if (o > 0)
		{
			key[0] = o + '0';
			key[1] = '\0';
			temp = find_mapping(mappings, count, key);
			if (temp)
				append_with_space(result, temp);
		}
	}
}

void	process_triplet(char *triplet, int group_index, char *result,
		t_mapping *mappings, int count)
{
	char	*triplet_text;
	char	*scale_name;

	triplet_text = convert_triplet(triplet, mappings, count);
	if (triplet_text[0])
	{
		append_with_space(result, triplet_text);
		scale_name = find_scale_name(mappings, count, group_index);
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
