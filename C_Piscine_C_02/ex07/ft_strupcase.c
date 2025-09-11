/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:57:28 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/11 17:33:15 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_lower_alpha(char c)
{
	return (c >= 'a' && c <= 'z');
}

char	*ft_strupcase(char *str)
{
	int	lower_upper_diff;
	int	i;

	lower_upper_diff = ('a' - 'A');
	i = 0;
	while (str[i])
	{
		if (ft_char_is_lower_alpha(str[i]))
			str[i] -= lower_upper_diff;
		i++;
	}
	return (str);
}
