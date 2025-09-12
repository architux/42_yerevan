/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 21:03:49 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/12 21:15:19 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*haystack;
	char	*needle;

	if (!*to_find)
		return (char *)str;
	while (*str)
	{
		haystack = str;
		needle = to_find;
		while (*needle && *needle == *haystack)
		{
			haystack++;
			needle++;
		}
		if (!*needle)
			return (char *)str;
		str++;
	}
	return NULL;
}
