/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 05:26:52 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/08 05:26:53 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
#define SOLVER_H

int	apply_obvious(int *grid, int n, int *clues);
int	solve(int *grid, int n, int pos, int *clues);

#endif
