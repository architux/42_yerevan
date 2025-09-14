/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:01:52 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/14 15:42:31 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_convert.h"

int	read_file(char *path, char **content)
{
	int		fd;
	char	buffer[4096];
	int		bytes;
	int		total;
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

int	count_lines(char *content)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (content[i])
	{
		if (content[i] == '\n')
			count++;
		i++;
	}
	if (i > 0 && content[i - 1] != '\n')
		count++;
	return (count);
}

char	**split_lines(char *content, int *line_count)
{
	char	**lines;
	int		count;
	int		i;
	int		j;
	int		start;

	count = count_lines(content);
	*line_count = count;
	lines = malloc(sizeof(char *) * (count + 1));
	if (!lines)
		return (0);
	i = 0;
	j = 0;
	start = 0;
	while (content[i])
	{
		if (content[i] == '\n')
		{
			lines[j] = extract_substring(content, start, i - start);
			j++;
			start = i + 1;
		}
		i++;
	}
	if (start < i)
		lines[j++] = extract_substring(content, start, i - start);
	lines[j] = 0;
	return (lines);
}

int	parse_mapping_line(char *line, char **key, char **value)
{
	int		i;
	int		colon_pos;
	char	*k;
	char	*v;

	colon_pos = -1;
	i = 0;
	while (line[i])
	{
		if (line[i] == ':')
		{
			colon_pos = i;
			break ;
		}
		i++;
	}
	if (colon_pos == -1)
		return (0);
	k = extract_substring(line, 0, colon_pos);
	v = extract_substring(line, colon_pos + 1,
			ft_strlen(line) - colon_pos - 1);
	*key = trim_whitespace(k);
	*value = trim_whitespace(v);
	free(k);
	free(v);
	if (!(*key)[0] || !(*value)[0])
		return (0);
	return (1);
}

t_mapping	*parse_dictionary(char *path, int *count)
{
	char		*content;
	char		**lines;
	int			line_count;
	t_mapping	*mappings;
	int			i;

	if (!read_file(path, &content))
		return (0);
	lines = split_lines(content, &line_count);
	free(content);
	if (!lines)
		return (0);
	mappings = malloc(sizeof(t_mapping) * line_count);
	*count = 0;
	i = 0;
	while (i < line_count)
	{
		if (lines[i][0] && !is_empty_line(lines[i]))
		{
			if (!parse_mapping_line(lines[i], &mappings[*count].key,
					&mappings[*count].value))
			{
				free_lines(lines, line_count);
				free_mappings(mappings, *count);
				return (0);
			}
			(*count)++;
		}
		i++;
	}
	free_lines(lines, line_count);
	return (mappings);
}
