/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:21:33 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/08 20:33:30 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	int				copy_len;
	int				i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size > 0)
	{
		if (src_len < size - 1)
			copy_len = src_len;
		else
			copy_len = size - 1;
		i = 0;
		while (i < copy_len)
		{
			dest[i] = src[i];
			i++;
		}
		dest[copy_len] = '\0';
	}
	return (src_len);
}
