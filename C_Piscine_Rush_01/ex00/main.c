/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 14:41:05 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/06 22:17:14 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	factorial(int n)
{
	int	fact;
	int	i;

	fact = 1;
	i = 2;
	while (i <= n)
	{
		fact *= i;
		i++;
	}
	return (fact);
}

void	write_int(int x)
{
	char	buffer[12];
	int	i;

	i = 0;
	if (x == 0)
	{
		write(1, "0", 1);
		return ;
	}
	while (x > 0)
	{
		buffer[i++] = '0' + (x % 10);
		x /= 10;
	}
	while (i > 0)
	{
		i--;
		write(1, &buffer[i], 1);
	}
}

void	parse_input(const char *input, int *arr);

int	*gen_values(int values_len);

void	gen_heap_perms(int *values, int size, int *perms, int *perm_idx);

int	main(void)
{
	char	*input;
	int	values_len;
	int	*values;
	int	*clues;
	int	perms_len;
	int	*perms;
	int	i;
	int	j;

	// Values
	values_len = 4;
	values = gen_values(values_len);
	if (!values)
	{
		write(2, "Memory allocation failed\n", 25);
		return (1);
	}
	// Clues
	input = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	clues = (int *)malloc(values_len * values_len * sizeof(int));
	parse_input(input, clues);
	i = 0;
	write(1, "Clues: ", 8);
	fflush(stdout);
	while (i < values_len * values_len)
	{
		printf("%i ", clues[i]);
		i++;
	}
	printf("\n");
	// Perms
	perms_len = factorial(values_len);
	perms = (int *)malloc(perms_len * values_len * sizeof(int) + sizeof(int));
	perms = perms + 1;
	perms[-1] = values_len;
	i = 0;
	gen_heap_perms(values, values_len, perms, &i);
	i = 0;
	write(1, "Perms: \n", 8);
	fflush(stdout);
	while (i < perms_len - 1)
	{
		write(1, "perm #", 6);
		write_int(i);
		write(1, ": ", 2);
		j = 0;
		while (j < values_len)
		{
			write_int(perms[i * values_len + j]);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	free(perms - 1);
	free(values);
	free(clues);
	return (0);
}
