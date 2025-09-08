/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 05:23:30 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/08 05:23:32 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

int	count_numbers(char *s);
int	parse_numbers(char *s, int *out, int max);
int	validate_vals(int *vals, int n);

#endif
