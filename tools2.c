/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <nouhaddo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:16:40 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/12/23 23:02:53 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static int	get_score1(char **board, int rows, int cols, t_choice pos)
{
	int		connects;
	int		i;

	connects = 0;
	i = 1;
	while (pos.col + i < cols && pos.row - i >= 0)
	{
		if (board[pos.row - i][pos.col + i] == pos.c)
			connects++;
		else
			break ;
		i++;
	}
	i = 1;
	while (pos.col - i >= 0 && pos.row + i < rows)
	{
		if (board[pos.row + i][pos.col - i] == pos.c)
			connects++;
		else
			break ;
		i++;
	}
	return (connects);
}

static int	get_score2(char **board, int rows, int cols, t_choice pos)
{
	int		connects;
	int		i;

	connects = 0;
	i = 1;
	while (pos.col - i >= 0 && pos.row - i >= 0)
	{
		if (board[pos.row - i][pos.col - i] == pos.c)
			connects++;
		else
			break ;
		i++;
	}
	i = 1;
	while (pos.col + i < cols && pos.row + i < rows)
	{
		if (board[pos.row][pos.col - i] == pos.c)
			connects++;
		else
			break ;
		i++;
	}
	return (connects);
}

static int	get_score3(char **board, int rows, t_choice pos)
{
	int connects;
	int i;

	i = 1;
	connects = 0;
	while (pos.row + i < rows)
	{
		if (board[pos.row + i][pos.col] == pos.c && i++)
			connects++;
		else
			break ;
		i++;
	}
	return (connects);
}

static int	get_score4(char **board, int cols, t_choice pos)
{
	int connects;
	int i;

	i = 1;
	connects = 0;
	while (pos.col + i < cols)
	{
		if (board[pos.row][pos.col + i] == pos.c)
			connects++;
		else
			break ;
		i++;
	}
	i = 1;
	while (pos.col - i >= 0)
	{
		if (board[pos.row][pos.col - i] == pos.c)
			connects++;
		else
			break ;
		i++;
	}
	return (connects);
}

int			get_score(char **board, int rows, int cols, t_choice pos)
{
	int score;
	int connects;

	score = 0;
	if ((connects = get_score1(board, rows, cols, pos)) > score)
		score = connects;
	if ((connects = get_score2(board, rows, cols, pos)) > score)
		score = connects;
	if ((connects = get_score3(board, rows, pos)) > score)
		score = connects;
	if ((connects = get_score4(board, cols, pos)) > score)
		score = connects;
	return (score);
}
