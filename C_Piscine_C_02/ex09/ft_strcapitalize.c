/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:41:11 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/08 20:16:59 by mvasilev         ###   ########.fr       */
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

int	ft_char_is_upper_alpha(char c)
{
	int	is_uppercase;

	if (c >= 'A' && c <= 'Z')
		is_uppercase = 1;
	else
		is_uppercase = 0;
	return (is_uppercase);
}

int	ft_char_is_numeric(char c)
{
	int	is_numeric;

	if (c >= '0' && c <= '9')
		is_numeric = 1;
	else
		is_numeric = 0;
	return (is_numeric);
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
