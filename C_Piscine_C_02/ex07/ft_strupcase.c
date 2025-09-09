/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:57:28 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/08 19:56:15 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_lower_alpha(char c)
{
	int	is_lowercase;

	if (c >= 'a' && c <= 'z')
		is_lowercase = 1;
	else
		is_lowercase = 0;
	return (is_lowercase);
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
