/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:47:40 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/03 22:14:03 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str);

int	main(void)
{
	char	before[49] = "hi, hOw are yOu? 42words forty-two; fiFty+aNd+oNe";
	char	after[49] = "Hi, How Are You? 42words Forty-Two; Fifty+And+One";

	printf("   phrase after: %s\n", ft_strcapitalize(before));
	printf("phrase to check: %s\n", after);
	return (0);
}
