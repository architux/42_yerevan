/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_heap_perms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:37:36 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/06 19:14:53 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	add_perm(int *values, int values_len, int *perms, int *perm_idx)
{
	int	i;

	i = 0;
	while (i < values_len)
	{
		perms[(*perm_idx) * values_len + i] = values[i];
		i++;
	}
	(*perm_idx)++;
}

void	gen_heap_perms(int *values, int size, int *perms, int *perm_idx)
{
	int	i;
	int	values_len;

	if (size == 1)
	{
		values_len = perms[-1];
		add_perm(values, values_len, perms, perm_idx);
		return ;
	}
	i = 0;
	while (i < size)
	{
		gen_heap_perms(values, size - 1, perms, perm_idx);
		if (size % 2 == 1)
			swap(&values[0], &values[size - 1]);
		else
			swap(&values[i], &values[size - 1]);
		i++;
	}
}
