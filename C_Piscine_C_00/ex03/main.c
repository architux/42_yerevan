/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:35:26 by mvasilev          #+#    #+#             */
/*   Updated: 2025/08/31 16:35:45 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void);

int	main(void)
{
	char	newline;

	newline = '\n';
	ft_print_numbers();
	write(1, &newline, 1);
}
