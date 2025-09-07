/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:41:13 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/07 23:21:34 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define SQUARE_SIDES_COUNT 4
#define INITIAL_CURSOR_INDEX 0
#define SOLUTION_FOUND 1
#define EXIT_CODE__SUCCESS 0
#define EXIT_CODE__ERROR__NO_CLUES_STRING 1
#define EXIT_CODE__ERROR__NO_CLUES_TO_PARSE 2
#define EXIT_CODE__ERROR__INVALID_CLUES_COUNT 3
#define EXIT_CODE__ERROR__NO_SOLUTION_FOUND 4

int		count_clues(char **argv);
int		*parse_clues(char **argv, int square_size);
int		*init_grid(int square_size);

int		no_clues_string_error(int argc);
int		no_clues_to_parse_error(int clues_count);
int		invalid_clues_count_error(int clues_count);
int		no_solution_found_error(int solver_result);

int		solve_grid(int *grid, int *clues, int square_size, int cursor);
void	print_grid(int *grid, int square_size);

int	main(int argc, char **argv)
{
	int	*clues;
	int	clues_count;
	int	*grid;
	int	square_size;
	int	solver_result;

	if (no_clues_string_error(argc))
		return (EXIT_CODE__ERROR__NO_CLUES_STRING);
	clues_count = count_clues(argv);
	if (no_clues_to_parse_error(clues_count))
		return (EXIT_CODE__ERROR__NO_CLUES_TO_PARSE);
	if (invalid_clues_count_error(clues_count))
		return (EXIT_CODE__ERROR__INVALID_CLUES_COUNT);
	square_size = clues_count / SQUARE_SIDES_COUNT;
	clues = parse_clues(argv, square_size);
	grid = init_grid(square_size);
	solver_result = solve_grid(grid, clues, square_size, INITIAL_CURSOR_INDEX);
	if (solver_result == SOLUTION_FOUND)
		print_grid(grid, square_size);
	free(grid);
	free(clues);
	if (no_solution_found_error(solver_result))
		return (EXIT_CODE__ERROR__NO_SOLUTION_FOUND);
	else
		return (EXIT_SUCCESS);
}
