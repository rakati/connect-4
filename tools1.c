/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <nouhaddo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:16:40 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/12/23 23:00:40 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		check_right(char **b, int cols, t_choice p)
{
	if (p.col + 3 < cols && b[p.row][p.col] == ' ')
		if (b[p.row][p.col + 1] == p.c &&
			b[p.row][p.col + 2] == p.c &&
			b[p.row][p.col + 3] == p.c)
			return (1);
	return (0);
}

int		check_down(char **b, int rows, t_choice p)
{
	if (p.row + 3 < rows && b[p.row][p.col] == ' ')
		if (b[p.row + 1][p.col] == p.c &&
			b[p.row + 2][p.col] == p.c &&
			b[p.row + 3][p.col] == p.c)
			return (1);
	return (0);
}

int		check_right_down(char **b, int rows, int cols, t_choice p)
{
	if (p.col + 3 < cols && p.row + 3 < rows && b[p.row][p.col] == ' ')
		if (b[p.row + 1][p.col + 1] == p.c &&
			b[p.row + 2][p.col + 2] == p.c &&
			b[p.row + 3][p.col + 3] == p.c)
			return (1);
	return (0);
}

int		check_left_down(char **b, int rows, int cols, t_choice p)
{
	if (p.col - 3 < cols && p.row + 3 < rows && b[p.row][p.col] == ' ')
		if (b[p.row + 1][p.col - 1] == p.c &&
			b[p.row + 2][p.col - 2] == p.c &&
			b[p.row + 3][p.col - 3] == p.c)
			return (1);
	return (0);
}

int		check_right_up(char **b, int rows, int cols, t_choice p)
{
	if (p.col + 3 < cols && p.row - 3 < rows && b[p.row][p.col] == ' ')
		if (b[p.row - 1][p.col + 1] == p.c &&
			b[p.row - 2][p.col + 2] == p.c &&
			b[p.row - 3][p.col + 3] == p.c)
			return (1);
	return (0);
}
