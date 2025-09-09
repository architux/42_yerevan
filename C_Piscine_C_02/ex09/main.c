/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:47:40 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/08 20:09:07 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str);

int	main(void)
{
	char	before[49] = "hi, hOw are yOu? 42WorDs forty-two; fiFty+aNd+oNe";
	char	after[49] = "Hi, How Are You? 42words Forty-Two; Fifty+And+One";

	printf("   phrase before: %s\n\n", before);
	ft_strcapitalize(before);
	printf("    phrase after: %s\n", before);
	printf(" phrase to check: %s\n", after);
	return (0);
}
