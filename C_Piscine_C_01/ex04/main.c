/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:33:09 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/01 18:40:41 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

int	main(void)
{
	int	a;
	int	b;

	a = 4;
	b = 2;
	printf("a is %i, b is %i\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("a is %i, b is %i\n", a, b);
}
