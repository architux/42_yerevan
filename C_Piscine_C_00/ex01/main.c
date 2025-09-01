/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:27:14 by mvasilev          #+#    #+#             */
/*   Updated: 2025/08/31 16:42:51 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void);

int	main(void)
{
	char	newline;

	newline = '\n';
	ft_print_alphabet();
	write(1, &newline, 1);
}
