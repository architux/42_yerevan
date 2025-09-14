/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:01:52 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/14 23:28:15 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_convert.h"

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

char	**split_lines(char *content, int *line_count, int i, int j)
{
	char	**lines;
	int		count;
	int		start;

	count = count_lines(content);
	*line_count = count;
	lines = malloc(sizeof(char *) * (count + 1));
	if (!lines)
		return (0);
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

	colon_pos = -1;
	i = 0;
	while (line[i])
	{
		if (line[i] == MAPPING_FILE_DELIMITER)
		{
			colon_pos = i;
			break ;
		}
		i++;
	}
	if (colon_pos == -1)
		return (0);
	*key = trim_whitespace(extract_substring(line, 0, colon_pos));
	*value = trim_whitespace(extract_substring(line, colon_pos + 1,
				ft_strlen(line) - colon_pos - 1));
	free(extract_substring(line, 0, colon_pos));
	free(extract_substring(line, colon_pos + 1,
			ft_strlen(line) - colon_pos - 1));
	if (!(*key)[0] || !(*value)[0])
		return (0);
	return (1);
}

int	free_stuff(char **lines, int line_count, t_mapping *mappings, int *count)
{
	int	i;

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
	return (1);
}

t_mapping	*parse_dictionary(char *path, int *count)
{
	char		*content;
	char		**lines;
	int			line_count;
	t_mapping	*mappings;

	if (!read_file(path, &content, 0))
		return (0);
	lines = split_lines(content, &line_count, 0, 0);
	free(content);
	if (!lines)
		return (0);
	mappings = malloc(sizeof(t_mapping) * line_count);
	*count = 0;
	if (!free_stuff(lines, line_count, mappings, count))
		return (0);
	free_lines(lines, line_count);
	return (mappings);
}
