/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:22:18 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/13 01:52:02 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define SQUARE_SIDES_COUNT 4
#define MIN_SQUARE_SIZE 4
#define MAX_SQUARE_SIZE 9
#define VALID_ARGC_COUNT 2
#define NO_SOLUTION_FOUND 0
#define EXIT_CODE__SUCCESS 0
#define EXIT_CODE__ERROR__NO_CLUES_STRING 1
#define EXIT_CODE__ERROR__NO_CLUES_TO_PARSE 2
#define EXIT_CODE__ERROR__INVALID_CLUES_COUNT 3
#define EXIT_CODE__ERROR__NO_SOLUTION_FOUND 4
#define ERROR_TEXT "Error\n"
#define ERROR_TEXT_SIZE 6

int	no_clues_string_error(int argc)
{
	if (argc != VALID_ARGC_COUNT)
	{
		write(STDERR_FILENO, ERROR_TEXT, ERROR_TEXT_SIZE);
		return (EXIT_CODE__ERROR__NO_CLUES_STRING);
	}
	else
		return (EXIT_CODE__SUCCESS);
}

int	no_clues_to_parse_error(int clues_count)
{
	if (!clues_count)
	{
		write(STDERR_FILENO, ERROR_TEXT, ERROR_TEXT_SIZE);
		return (EXIT_CODE__ERROR__NO_CLUES_TO_PARSE);
	}
	else
		return (EXIT_CODE__SUCCESS);
}

int	invalid_clues_count_error(int clues_count)
{
	int	div;
	int	mod;

	div = clues_count / SQUARE_SIDES_COUNT;
	mod = clues_count % SQUARE_SIDES_COUNT;
	if (mod != 0)
	{
		write(STDERR_FILENO, ERROR_TEXT, ERROR_TEXT_SIZE);
		return (EXIT_CODE__ERROR__INVALID_CLUES_COUNT);
	}
	else if (div < MIN_SQUARE_SIZE || div > MAX_SQUARE_SIZE)
	{
		write(STDERR_FILENO, ERROR_TEXT, ERROR_TEXT_SIZE);
		return (EXIT_CODE__ERROR__INVALID_CLUES_COUNT);
	}
	else
		return (EXIT_CODE__SUCCESS);
}

int	no_solution_found_error(int solver_result)
{
	if (solver_result == NO_SOLUTION_FOUND)
	{
		write(STDERR_FILENO, ERROR_TEXT, ERROR_TEXT_SIZE);
		return (EXIT_CODE__ERROR__NO_SOLUTION_FOUND);
	}
	else
		return (EXIT_CODE__SUCCESS);
}
