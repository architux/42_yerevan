/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:42:56 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/15 21:35:21 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*dest_initial_pointer;

	dest_initial_pointer = dest;
	while (*dest)
		dest++;
	while (nb > 0 && *src)
	{
		*dest++ = *src++;
		nb--;
	}
	*dest = '\0';
	return (dest_initial_pointer);
}
