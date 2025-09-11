/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:41:11 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/11 17:31:23 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_lower_alpha(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_char_is_upper_alpha(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_char_is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_char_is_alphanumeric(char c)
{
	return (ft_char_is_lower_alpha(c)
		|| ft_char_is_upper_alpha(c)
		|| ft_char_is_numeric(c));
}

char	*ft_strcapitalize(char *str)
{
	int	lower_upper_diff;
	int	i;
	int	start_of_word;

	lower_upper_diff = ('a' - 'A');
	i = 0;
	start_of_word = 1;
	while (str[i])
	{
		if (ft_char_is_alphanumeric(str[i]))
		{
			if (start_of_word && ft_char_is_lower_alpha(str[i]))
			{
				str[i] -= lower_upper_diff;
				start_of_word = 0;
			}
			else if (!start_of_word && ft_char_is_upper_alpha(str[i]))
				str[i] += lower_upper_diff;
			start_of_word = 0;
		}
		else
			start_of_word = 1;
		i++;
	}
	return (str);
}
