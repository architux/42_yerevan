/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:02:21 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/14 21:13:41 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_convert.h"

int	check_duplicate_keys(t_mapping *mappings, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_strcmp(mappings[i].key, mappings[j].key) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_required_mappings(t_mapping *dict, int dict_count,
		t_mapping *req, int req_count)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	while (i < req_count)
	{
		found = 0;
		j = 0;
		while (j < dict_count)
		{
			if (ft_strcmp(req[i].key, dict[j].key) == 0)
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (!found)
			return (0);
		i++;
	}
	return (1);
}

int	validate_dictionary(t_mapping *mappings, int count)
{
	t_mapping	*required;
	int			req_count;

	if (!validate_dict_keys(mappings, count))
		return (0);
	if (!check_duplicate_keys(mappings, count))
		return (0);
	required = parse_dictionary(REQUIRED_MAPPING_FILE_NAME, &req_count);
	if (!required)
		return (0);
	if (!check_required_mappings(mappings, count, required, req_count))
		return (0);
	if (!check_acceptable_keys(mappings, count))
		return (0);
	free_mappings(required, req_count);
	return (1);
}

int	can_convert_number(char *number, t_mapping *mappings, int count)
{
	int		len;
	int		groups;
	int		i;
	int		group_num;

	len = ft_strlen(number);
	if (len == 1 && number[0] == '0')
		return (find_mapping(mappings, count, "0") != 0);
	groups = (len + 2) / 3;
	i = groups - 1;
	while (i >= 0)
	{
		group_num = groups - i - 1;
		if (group_num > 0)
		{
			if (!find_scale_name(mappings, count, group_num))
				return (0);
		}
		i--;
	}
	return (1);
}
