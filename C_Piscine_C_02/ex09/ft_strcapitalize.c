/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:41:11 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/04 16:11:19 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_lower_alpha(char c)
{
	int	is_lower_letter;

	if (c >= 'a' && c <= 'z')
		is_lower_letter = 1;
	else
		is_lower_letter = 0;
	return (is_lower_letter);
}

int	ft_char_is_upper_alpha(char c)
{
	int	is_upper_letter;

	if (c >= 'A' && c <= 'Z')
		is_upper_letter = 1;
	else
		is_upper_letter = 0;
	return (is_upper_letter);
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
	int	i;
	int	start_of_word;

	i = 0;
	start_of_word = 1;
	while (str[i])
	{
		if (ft_char_is_alphanumeric(str[i]))
		{
			if (start_of_word && ft_char_is_lower_alpha(str[i]))
			{
				str[i] -= ('a' - 'A');
				start_of_word = 0;
			}
			else if (!start_of_word && ft_char_is_upper_alpha(str[i]))
				str[i] += ('a' - 'A');
			start_of_word = 0;
		}
		else
			start_of_word = 1;
		i++;
	}
	return (str);
}
