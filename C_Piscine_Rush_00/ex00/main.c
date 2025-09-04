/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamrazy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:16:04 by etamrazy          #+#    #+#             */
/*   Updated: 2025/08/30 17:58:21 by etamrazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	rush(int x, int y);

void	ft_putchar(char c);

int	main(void)
{
	rush(5, 3);
	ft_putchar('\n');
	rush(5, 1);
	ft_putchar('\n');
	rush(1, 1);
	ft_putchar('\n');
	rush(1, 5);
	ft_putchar('\n');
	rush(4, 4);
	ft_putchar('\n');
	return (0);
}
