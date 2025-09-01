/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:52:38 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/01 21:26:02 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_ft(int *********nbr);

int	main(void)
{
	int	number;
	int* n1;
	int** n2;
	int*** n3;
	int**** n4;
	int***** n5;
	int****** n6;
	int******* n7;
	int******** n8;
	int********* n9;

	number = 0;
	n1 = &number;
	n2 = &n1;
	n3 = &n2;
	n4 = &n3;
	n5 = &n4;
	n6 = &n5;
	n7 = &n6;
	n8 = &n7;
	n9 = &n8;
	printf("Before ft_ultimate_ft: %i\n", number);
	ft_ultimate_ft(n9);
	printf("After ft_ultimate_ft: %i\n", number);
}
