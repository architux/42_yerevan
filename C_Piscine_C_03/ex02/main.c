/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 22:16:01 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/09 22:26:13 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	char	str_src[] = "XYZ";
	char	str_dest[] = "ABC";

	printf("        str_src: %s\n", str_src);
	printf("str_dest before: %s\n", str_dest);
	ft_strcat(str_dest, str_src);
	printf(" str_dest after: %s\n", str_dest);
	return (0);
}
