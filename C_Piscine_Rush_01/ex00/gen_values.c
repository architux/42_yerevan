/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:32:07 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/06 17:36:47 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*gen_values(int values_len)
{
	int	*values;
	int	i;

	values = (int *)malloc(values_len * sizeof(int));
	if (!values)
		return (NULL);
	i = 0;
	while (i < values_len)
	{
		values[i] = i + 1;
		i++;
	}
	return (values);
}
