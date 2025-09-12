/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 21:16:34 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/12 21:22:22 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	dest_len = ft_strlen(dest);
	int	src_len = ft_strlen(src);
	int	total_len = dest_len + src_len;
	int	copy_len;
	int	i;

	if (size == 0)
		return total_len;
	if (dest_len >= size)
		return total_len;
	copy_len = size - dest_len - 1;
	if (src_len < copy_len)
		copy_len = src_len;
	i = 0;
	while (i < copy_len)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + copy_len] = '\0';
	return (total_len);
}
