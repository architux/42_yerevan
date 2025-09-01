/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:31:00 by mvasilev          #+#    #+#             */
/*   Updated: 2025/08/31 16:32:36 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void);

int	main(void)
{
	char	newline;

	newline = '\n';
	ft_print_reverse_alphabet();
	write(1, &newline, 1);
}
