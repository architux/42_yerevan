/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:39:33 by mvasilev          #+#    #+#             */
/*   Updated: 2025/08/31 18:10:09 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_is_negative(int n);

int	main(void)
{
	int	number;

	number = 42;
	printf("%i number is ", number);
	fflush(stdout);
	ft_is_negative(number);
	printf("\n");
	number = 0;
	printf("%i number is ", number);
	fflush(stdout);
	ft_is_negative(number);
	printf("\n");
	number = -42;
	printf("%i number is ", number);
	fflush(stdout);
	ft_is_negative(number);
	printf("\n");
}
