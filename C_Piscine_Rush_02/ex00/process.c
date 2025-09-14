/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:04:06 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/14 23:24:11 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_convert.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;
	int		i;

	len = ft_strlen(src);
	dest = malloc(len + 1);
	if (!dest)
		return (0);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*process_conversion(char *dict_path, char *number)
{
	t_mapping	*mappings;
	int			count;
	char		*result;

	mappings = parse_dictionary(dict_path, &count);
	if (!mappings)
	{
		set_last_error(MAPPING_ERROR_EXIT_CODE);
		return (0);
	}
	if (!validate_dictionary(mappings, count)
		|| !can_convert_number(number, mappings, count))
	{
		free_mappings(mappings, count);
		set_last_error(MAPPING_ERROR_EXIT_CODE);
		return (0);
	}
	result = convert_number(number, mappings, count);
	free_mappings(mappings, count);
	return (result);
}

int	print_result(int argc, char *dict_path, char *number_str)
{
	char	*result;

	if (!validate_number(&number_str))
		return (handle_error(ARGS_ERROR_EXIT_CODE));
	result = process_conversion(dict_path, number_str);
	if (!result)
		return (handle_error(get_last_error()));
	write(STDOUT_FILENO, result, ft_strlen(result));
	write(STDOUT_FILENO, "\n", 1);
	free(result);
	free(number_str);
	if (argc == USECASE_B)
		free(dict_path);
	return (SUCCESS_EXIT_CODE);
}
