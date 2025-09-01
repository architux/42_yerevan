/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:55:18 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/01 20:10:08 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	start_index;
	int	end_index;
	int	temp;

	start_index = 0;
	end_index = size - 1;
	while (start_index < end_index)
	{
		temp = tab[start_index];
		tab[start_index] = tab[end_index];
		tab[end_index] = temp;
		start_index++;
		end_index--;
	}
}
