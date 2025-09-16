/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 23:40:54 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/16 20:45:44 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../../.tests/test.h"

int	ft_atoi(char *str);

void	test(char *str)
{
	printf("ft_atoi: %i\n", ft_atoi(str));
	printf("   atoi: %i\n", atoi(str));
	printf("\n");
}

int	main(void)
{
	test(" \n\v---+--+1234ab567");
	test("+123z4ab567");
	return (0);
}
