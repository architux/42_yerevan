/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 05:14:56 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/08 05:04:31 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src);

int	main(void)
{
	char	dest_longer[19] = "xxxxxxxxxxxxxxxxxx";
	char	dest_equal[7] = "xxxxxx";
	char	dest_shorter[4] = "xxx";
	char	src[7] = "tststr";

	printf("dest  > src  ft_strncpy: .%s.\n", ft_strcpy(dest_longer, src));
	printf("dest  > src     strncpy: .%s.\n", strcpy(dest_longer, src));
	printf("\n");
	printf("dest  == src ft_strncpy: .%s.\n", ft_strcpy(dest_equal, src));
	printf("dest  == src    strncpy: .%s.\n", strcpy(dest_equal, src));
	printf("\n");
	printf("dest < src   ft_strncpy: .%s.\n", ft_strcpy(dest_shorter, src));
	printf("dest < src      strncpy: .%s.\n", strcpy(dest_shorter, src));
	return (0);
}
