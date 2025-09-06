/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:15:50 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/03 20:35:18 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str);

int	main(void)
{
	char	has_lower_str[11] = "aB1cD2eF3g4";

	printf("has_lower_str before: %s\n", has_lower_str);
	printf("has_lower_str  after: %s\n", ft_strupcase(has_lower_str));
	return (0);
}
