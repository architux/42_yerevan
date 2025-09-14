/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:00:46 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/14 15:08:59 by mvasilev         ###   ########.fr       */
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

int	handle_error(int code)
{
	if (code == 1)
		write(1, "Error\n", 6);
	else if (code == 2)
		write(1, "Error\n", 6);
	else if (code == 3)
		write(1, "Dict Error\n", 11);
	else if (code == 4)
		write(1, "Dict Error\n", 11);
	return (code);
}

int	main(int argc, char **argv)
{
	char	*dict_path;
	char	*number_str;
	char	*result;

	if (argc != 2 && argc != 3)
		return (handle_error(1));
	if (argc == 2)
	{
		dict_path = "numbers.dict";
		number_str = trim_whitespace(argv[1]);
	}
	else
	{
		dict_path = trim_whitespace(argv[1]);
		number_str = trim_whitespace(argv[2]);
	}
	if (!validate_number(&number_str))
		return (handle_error(2));
	result = process_conversion(dict_path, number_str);
	if (!result)
		return (handle_error(get_last_error()));
	write(1, result, ft_strlen(result));
	write(1, "\n", 1);
	free(result);
	free(number_str);
	if (argc == 3)
		free(dict_path);
	return (0);
}
