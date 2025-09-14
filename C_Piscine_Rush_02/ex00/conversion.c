/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:02:52 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/14 23:32:27 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_convert.h"

char	*find_mapping(t_mapping *mappings, int count, char *key)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (ft_strcmp(mappings[i].key, key) == 0)
			return (mappings[i].value);
		i++;
	}
	return (0);
}

char	*convert_hundreds(int *arr, t_mapping *mappings, int count)
{
	char	*result;
	char	*temp;
	char	key[4];

	result = malloc(1024);
	result[0] = '\0';
	if (arr[0] > 0)
	{
		key[0] = arr[0] + '0';
		key[1] = '\0';
		temp = find_mapping(mappings, count, key);
		if (temp)
			append_with_space(result, temp);
		temp = find_mapping(mappings, count, "100");
		if (temp)
			append_with_space(result, temp);
	}
	convert_tens_ones(arr, result, mappings, count);
	return (result);
}

char	*convert_triplet(char *triplet, t_mapping *mappings, int count)
{
	int		arr[3];
	char	*result;

	arr[0] = triplet[0] - '0';
	arr[1] = triplet[1] - '0';
	arr[2] = triplet[2] - '0';
	if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
		return (ft_strdup(""));
	result = convert_hundreds(arr, mappings, count);
	return (result);
}

char	*find_scale_name(t_mapping *mappings, int count, int group_index)
{
	char	scale_key[64];
	int		i;
	int		j;

	if (group_index == 0)
		return ("");
	scale_key[0] = '1';
	i = 1;
	j = 0;
	while (j < group_index * 3)
	{
		scale_key[i] = '0';
		i++;
		j++;
	}
	scale_key[i] = '\0';
	return (find_mapping(mappings, count, scale_key));
}

char	*convert_number(char *number, t_mapping *mappings, int count)
{
	char	*result;
	char	*padded;
	char	triplet[4];
	int		arr[2];
	int		i;

	arr[1] = count;
	if (ft_strlen(number) == 1 && number[0] == '0')
		return (ft_strdup(find_mapping(mappings, count, "0")));
	padded = pad_number(number);
	arr[0] = ft_strlen(padded) / 3;
	result = malloc(4096);
	result[0] = '\0';
	i = 0;
	while (i < arr[0])
	{
		extract_triplet(padded, i, triplet);
		arr[0] = arr[0] - i - 1;
		process_triplet(triplet, arr, result, mappings);
		arr[0] = arr[0] + i + 1;
		i++;
	}
	free(padded);
	return (result);
}
