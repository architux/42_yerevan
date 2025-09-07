/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 05:26:12 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/07 15:23:06 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	str_len(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	write_str(char *s)
{
	int	len;

	len = str_len(s);
	if (len > 0)
		write(1, s, len);
}

void	write_char(char c)
{
	int	dummy;

	dummy = write(1, &c, 1);
	(void)dummy;
}

void	write_int(int n)
{
	char	buf[12];
	int		idx;
	int		t;

	idx = 0;
	if (n == 0)
	{
		write_char('0');
		return ;
	}
	if (n < 0)
	{
		write_char('-');
		n = -n;
	}
	while (n > 0)
	{
		t = n % 10;
		buf[idx] = (char)('0' + t);
		idx++;
		n = n / 10;
	}
	while (idx > 0)
	{
		idx--;
		write_char(buf[idx]);
	}
}

int	count_numbers(char *s)
{
	int	i;
	int	cnt;
	int	in_num;

	i = 0;
	cnt = 0;
	in_num = 0;
	while (s && s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			if (!in_num)
			{
				cnt++;
				in_num = 1;
			}
		}
		else
			in_num = 0;
		i++;
	}
	return (cnt);
}

int	parse_numbers(char *s, int *out, int max)
{
	int	i;
	int	k;
	int	cur;
	int	in_num;

	i = 0;
	k = 0;
	cur = 0;
	in_num = 0;
	while (s && s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			cur = cur * 10 + (s[i] - '0');
			in_num = 1;
		}
		else
		{
			if (in_num)
			{
				if (k < max)
				{
					out[k] = cur;
					k++;
				}
				cur = 0;
				in_num = 0;
			}
		}
		i++;
	}
	if (in_num && k < max)
	{
		out[k] = cur;
		k++;
	}
	return (k);
}

int	visible_count(int *arr, int n)
{
	int	i;
	int	maxh;
	int	cnt;

	i = 0;
	maxh = 0;
	cnt = 0;
	while (i < n)
	{
		if (arr[i] > maxh)
		{
			maxh = arr[i];
			cnt++;
		}
		i++;
	}
	return (cnt);
}

int	row_complete(int *grid, int n, int row)
{
	int	j;
	int	idx;

	j = 0;
	while (j < n)
	{
		idx = row * n + j;
		if (grid[idx] == 0)
			return (0);
		j++;
	}
	return (1);
}

int	col_complete(int *grid, int n, int col)
{
	int	i;
	int	idx;

	i = 0;
	while (i < n)
	{
		idx = i * n + col;
		if (grid[idx] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_row_clues(int *grid, int n, int row, int *clues)
{
	int	j;
	int	*buf;
	int	leftv;
	int	rightv;
	int	cntl;
	int	cntr;

	buf = (int *)malloc(sizeof(int) * n);
	j = 0;
	while (j < n)
	{
		buf[j] = grid[row * n + j];
		j++;
	}
	leftv = clues[2 * n + row];
	rightv = clues[3 * n + row];
	cntl = visible_count(buf, n);
	j = 0;
	while (j < n)
	{
		buf[j] = grid[row * n + (n - 1 - j)];
		j++;
	}
	cntr = visible_count(buf, n);
	free(buf);
	if (cntl != leftv)
		return (0);
	if (cntr != rightv)
		return (0);
	return (1);
}

int	check_col_clues(int *grid, int n, int col, int *clues)
{
	int	i;
	int	*buf;
	int	topv;
	int	botv;
	int	cntt;
	int	cntb;

	buf = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		buf[i] = grid[i * n + col];
		i = i + 1;
	}
	topv = clues[0 * n + col];
	botv = clues[1 * n + col];
	cntt = visible_count(buf, n);
	i = 0;
	while (i < n)
	{
		buf[i] = grid[(n - 1 - i) * n + col];
		i++;
	}
	cntb = visible_count(buf, n);
	free(buf);
	if (cntt != topv)
		return (0);
	if (cntb != botv)
		return (0);
	return (1);
}

int	is_safe(int *grid, int n, int pos, int val)
{
	int	row;
	int	col;
	int	k;
	int	idx;

	row = pos / n;
	col = pos % n;
	k = 0;
	while (k < n)
	{
		idx = row * n + k;
		if (grid[idx] == val)
			return (0);
		k++;
	}
	k = 0;
	while (k < n)
	{
		idx = k * n + col;
		if (grid[idx] == val)
			return (0);
		k++;
	}
	return (1);
}

int	next_empty(int *grid, int n, int start)
{
	int	p;

	p = start;
	while (p < n * n)
	{
		if (grid[p] == 0)
			return (p);
		p++;
	}
	return (-1);
}

int	check_final(int *grid, int n, int *clues)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (!check_row_clues(grid, n, i, clues))
			return (0);
		if (!check_col_clues(grid, n, i, clues))
			return (0);
		i++;
	}
	return (1);
}

int	apply_obvious(int *grid, int n, int *clues)
{
	int	j;
	int	i;
	int	ok;
	int	idx;

	ok = 1;
	j = 0;
	while (j < n)
	{
		if (clues[j] == 1)
		{
			idx = 0 * n + j;
			if (grid[idx] != 0 && grid[idx] != n)
			{
				return (0);
			}
			grid[idx] = n;
		}
		if (clues[j] == n)
		{
			i = 0;
			while (i < n)
			{
				idx = i * n + j;
				if (grid[idx] != 0 && grid[idx] != (i + 1))
				{
					return (0);
				}
				grid[idx] = i + 1;
				i++;
			}
		}
		if (clues[n + j] == 1)
		{
			idx = (n - 1) * n + j;
			if (grid[idx] != 0 && grid[idx] != n)
			{
				return (0);
			}
			grid[idx] = n;
		}
		if (clues[n + j] == n)
		{
			i = 0;
			while (i < n)
			{
				idx = (n - 1 - i) * n + j;
				if (grid[idx] != 0 && grid[idx] != (i + 1))
				{
					return (0);
				}
				grid[idx] = i + 1;
				i++;
			}
		}
		j = j + 1;
	}
	i = 0;
	while (i < n)
	{
		if (clues[2 * n + i] == 1)
		{
			idx = i * n + 0;
			if (grid[idx] != 0 && grid[idx] != n)
			{
				return (0);
			}
			grid[idx] = n;
		}
		if (clues[2 * n + i] == n)
		{
			j = 0;
			while (j < n)
			{
				idx = i * n + j;
				if (grid[idx] != 0 && grid[idx] != (j + 1))
				{
					return (0);
				}
				grid[idx] = j + 1;
				j = j + 1;
			}
		}
		if (clues[3 * n + i] == 1)
		{
			idx = i * n + (n - 1);
			if (grid[idx] != 0 && grid[idx] != n)
			{
				return (0);
			}
			grid[idx] = n;
		}
		if (clues[3 * n + i] == n)
		{
			j = 0;
			while (j < n)
			{
				idx = i * n + (n - 1 - j);
				if (grid[idx] != 0 && grid[idx] != (j + 1))
				{
					return (0);
				}
				grid[idx] = j + 1;
				j = j + 1;
			}
		}
		i = i + 1;
	}
	return (ok);
}

int	solve(int *grid, int n, int pos, int *clues)
{
	int	next;
	int	val;
	int	row;
	int	col;

	next = next_empty(grid, n, pos);
	if (next == -1)
	{
		if (check_final(grid, n, clues))
			return (1);
		return (0);
	}
	val = 1;
	while (val <= n)
	{
		if (is_safe(grid, n, next, val))
		{
			grid[next] = val;
			row = next / n;
			col = next % n;
			if (row_complete(grid, n, row))
			{
				if (!check_row_clues(grid, n, row, clues))
				{
					grid[next] = 0;
					val++;
					continue ;
				}
			}
			if (col_complete(grid, n, col))
			{
				if (!check_col_clues(grid, n, col, clues))
				{
					grid[next] = 0;
					val++;
					continue ;
				}
			}
			if (solve(grid, n, next + 1, clues))
				return (1);
			grid[next] = 0;
		}
		val++;
	}
	return (0);
}

void	print_grid(int *grid, int n)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			idx = i * n + j;
			write_int(grid[idx]);
			if (j + 1 < n)
				write_char(' ');
			j++;
		}
		write_char('\n');
		i++;
	}
}

int	validate_vals(int *vals, int n)
{
	int	i;

	i = 0;
	while (i < 4 * n)
	{
		if (vals[i] < 1 || vals[i] > n)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	n;
	int	m;
	int	ok;
	int	*vals;
	int	count;
	int	*grid;

	n = 0;
	m = 0;
	ok = 1;
	vals = 0;
	count = 0;
	grid = 0;
	if (argc < 2)
	{
		write_str("Error\n");
		return (1);
	}
	count = count_numbers(argv[1]);
	if (count % 4 != 0)
	{
		write_str("Error\n");
		return (1);
	}
	n = count / 4;
	vals = (int *)malloc(sizeof(int) * count);
	if (!vals)
	{
		write_str("Error\n");
		return (1);
	}
	m = parse_numbers(argv[1], vals, count);
	if (m != count)
	{
		free(vals);
		write_str("Error\n");
		return (1);
	}
	if (!validate_vals(vals, n))
	{
		free(vals);
		write_str("Error\n");
		return (1);
	}
	grid = (int *)malloc(sizeof(int) * n * n);
	if (!grid)
	{
		free(vals);
		write_str("Error\n");
		return (1);
	}
	m = 0;
	while (m < n * n)
	{
		grid[m] = 0;
		m = m + 1;
	}
	ok = apply_obvious(grid, n, vals);
	if (!ok)
	{
		free(grid);
		free(vals);
		write_str("Error\n");
		return (1);
	}
	ok = solve(grid, n, 0, vals);
	if (!ok)
	{
		free(grid);
		free(vals);
		write_str("Error\n");
		return (1);
	}
	print_grid(grid, n);
	free(grid);
	free(vals);
	return (0);
}
