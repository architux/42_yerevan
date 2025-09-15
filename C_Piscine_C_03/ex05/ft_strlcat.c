/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 21:16:34 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/15 21:56:16 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	copy_len;
	unsigned int	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (src_len + size);
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
	return (dest_len + src_len);
}
