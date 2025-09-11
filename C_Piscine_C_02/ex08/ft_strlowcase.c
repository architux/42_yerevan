/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:36:31 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/11 17:32:31 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_upper_alpha(char c)
{
	return (c >= 'A' && c <= 'Z');
}

char	*ft_strlowcase(char *str)
{
	int	lower_upper_diff;
	int	i;

	lower_upper_diff = ('a' - 'A');
	i = 0;
	while (str[i])
	{
		if (ft_char_is_upper_alpha(str[i]))
			str[i] += lower_upper_diff;
		i++;
	}
	return (str);
}
