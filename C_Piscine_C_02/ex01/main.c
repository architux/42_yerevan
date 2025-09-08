/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 05:50:59 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/08 05:05:42 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	char			dest_longer[19] = "xxxxxxxxxxxxxxxxxx";
	char			dest_equal[7] = "xxxxxx";
	char			dest_shorter[4] = "xxx";
	char			src[7] = "tststr";
	unsigned int	n = 3;

	printf("dest  >  src ft_strncpy: .%s.\n", ft_strncpy(dest_longer, src, n));
	printf("dest  >  src    strncpy: .%s.\n", strncpy(dest_longer, src, n));
	printf("\n");
	printf("dest  == src ft_strncpy: .%s.\n", ft_strncpy(dest_equal, src, n));
	printf("dest  == src    strncpy: .%s.\n", strncpy(dest_equal, src, n));
	printf("\n");
	printf("dest  <  src ft_strncpy: .%s.\n", ft_strncpy(dest_shorter, src, n));
	printf("dest  <  src    strncpy: .%s.\n", strncpy(dest_shorter, src, n));
	return (0);
}
