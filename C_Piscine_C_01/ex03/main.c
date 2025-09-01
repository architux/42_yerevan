/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:26:50 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/01 18:30:46 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = 4;
	b = 2;
	div = -1;
	mod = -1;
	printf("a is %i, b is %i\n", a, b);
	printf("div is %i, mod is %i\n", div, mod);
	ft_div_mod(a, b, &div, &mod);
	printf("\n");
	printf("a is %i, b is %i\n", a, b);
	printf("div is %i, mod is %i\n", div, mod);
}
