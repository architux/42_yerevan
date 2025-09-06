/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:37:14 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/03 20:39:52 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str);

int	main(void)
{
	char	has_upper_str[11] = "aB1cD2eF3g4";

	printf("has_upper_str before: %s\n", has_upper_str);
	printf("has_upper_str  after: %s\n", ft_strlowcase(has_upper_str));
	return (0);
}
