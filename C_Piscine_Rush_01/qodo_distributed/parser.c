/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 05:25:04 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/08 05:25:06 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"

int	count_numbers(char *s)
{
	int	i;
	int	cnt;
	int	in_num;

	i = 0;
	cnt = 0;
	in_num = 0;
	while (s && s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			if (!in_num)
			{
				cnt++;
				in_num = 1;
			}
		}
		else
			in_num = 0;
		i++;
	}
	return (cnt);
}

int	parse_numbers(char *s, int *out, int max)
{
	int	i;
	int	k;
	int	cur;
	int	in_num;

	i = 0;
	k = 0;
	cur = 0;
	in_num = 0;
	while (s && s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			cur = cur * 10 + (s[i] - '0');
			in_num = 1;
		}
		else
		{
			if (in_num)
			{
				if (k < max)
				{
					out[k] = cur;
					k++;
				}
				cur = 0;
				in_num = 0;
			}
		}
		i++;
	}
	if (in_num && k < max)
	{
		out[k] = cur;
		k++;
	}
	return (k);
}

int	validate_vals(int *vals, int n)
{
	int	i;

	i = 0;
	while (i < 4 * n)
	{
		if (vals[i] < 1 || vals[i] > n)
			return (0);
		i++;
	}
	return (1);
}
