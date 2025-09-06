/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 21:22:23 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/06 22:09:04 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_to_int(const char *str, int *length_parsed)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	*length_parsed = i;
	return (result);
}

void	parse_input(const char *input, int *arr)
{
	int	cursor;
	int	i;
	int	parsed_int;
	int	length_parsed;

	cursor = 0;
	i = 0;
	while (input[cursor] != '\0')
	{
		while (input[cursor] == ' ')
		{
			cursor++;
		}
		parsed_int = str_to_int(&input[cursor], &length_parsed);
		arr[i++] = parsed_int;
		cursor += length_parsed;
	}
}
