/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:00:46 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/14 23:24:24 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_convert.h"

int	main(int argc, char **argv)
{
	char	*dict_path;
	char	*number_str;

	error_file_init();
	if (argc == USECASE_A)
	{
		dict_path = DEFAULT_MAPPING_FILE_NAME;
		number_str = trim_whitespace(argv[1]);
	}
	else if (argc == USECASE_B)
	{
		dict_path = trim_whitespace(argv[1]);
		number_str = trim_whitespace(argv[2]);
	}
	else
		return (handle_error(ARGS_ERROR_EXIT_CODE));
	return (print_result(argc, dict_path, number_str));
}
