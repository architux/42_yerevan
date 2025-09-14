/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:07:09 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/14 22:08:10 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_convert.h"

void	error_file_init(void)
{
	int		fd;

	fd = open(LAST_ERROR_FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return ;
	write(fd, "0", 1);
	close(fd);
}

int	get_last_error(void)
{
	int		fd;
	char	c;
	int		error;

	fd = open(LAST_ERROR_FILE_NAME, O_RDONLY);
	if (fd < 0)
		return (0);
	if (read(fd, &c, 1) != 1)
	{
		close(fd);
		return (0);
	}
	error = c - '0';
	close(fd);
	return (error);
}

void	set_last_error(int error)
{
	int		fd;
	char	c;

	fd = open(LAST_ERROR_FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return ;
	c = error + '0';
	write(fd, &c, 1);
	close(fd);
}

int	handle_error(int code)
{
	if (code == ARGS_ERROR_EXIT_CODE)
		write(STDERR_FILENO, ARGS_ERROR_TEXT, ARGS_ERROR_LEN);
	else if (code == MAPPING_ERROR_EXIT_CODE)
		write(STDERR_FILENO, MAPPING_ERROR_TEXT, MAPPING_ERROR_LEN);
	return (code);
}
