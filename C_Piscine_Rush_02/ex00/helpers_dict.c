/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 21:12:17 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/14 22:42:27 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_convert.h"

int	read_file(char *path, char **content, int total)
{
	int		fd;
	char	buffer[4096];
	int		bytes;
	char	*result;

	fd = open(path, 0);
	if (fd < 0)
		return (0);
	total = 0;
	bytes = read(fd, buffer, 4096);
	while (bytes > 0)
	{
		total = total + bytes;
		bytes = read(fd, buffer, 4096);
	}
	close(fd);
	result = malloc(total + 1);
	if (!result)
		return (0);
	fd = open(path, 0);
	bytes = read(fd, result, total);
	result[total] = '\0';
	close(fd);
	*content = result;
	return (1);
}

int	validate_dict_key(char *key)
{
	int	i;

	if (!key || !key[0])
		return (0);
	i = 0;
	while (key[i])
	{
		if (!is_digit(key[i]))
			return (0);
		i++;
	}
	return (1);
}

int	validate_dict_keys(t_mapping *mappings, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!validate_dict_key(mappings[i].key))
			return (0);
		i++;
	}
	return (1);
}

int	validate_acceptable_key(char *s)
{
	int	len;
	int	zeros_count;
	int	i;

	if (s[0] != '1')
		return (0);
	len = ft_strlen(s);
	i = 1;
	while (i < len)
	{
		if (s[i] != '0')
			return (0);
		i++;
	}
	zeros_count = len - 1;
	if (zeros_count % 3 != 0)
		return (0);
	if (zeros_count <= REQUIRED_MAPPINGS_MAX_KEY_LEN)
		return (0);
	return (1);
}

int	check_acceptable_keys(t_mapping *mappings, int count)
{
	char	keys_count;
	int		i;

	keys_count = count;
	i = 0;
	while (i < count)
	{
		if (validate_acceptable_key(mappings[i].key))
			keys_count--;
		i++;
	}
	if (keys_count > REQUIRED_MAPPINGS_COUNT)
		return (0);
	return (1);
}
