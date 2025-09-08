/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 05:20:27 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/08 05:20:34 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
#define IO_H

int str_len(char *s);
void write_str(char *s);
void write_char(char c);
void write_int(int n);
void print_grid(int *grid, int n);

#endif
