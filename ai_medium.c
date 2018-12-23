/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <nouhaddo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:16:40 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/12/23 22:11:58 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		check_right(char **b, int rows, int cols, t_choice p)
{
	if (p.col + 3 < cols && b[p.row][p.col] == ' ')
		if (	b[p.row][p.col + 1] == p.c &&
				b[p.row][p.col + 2] == p.c &&
				b[p.row][p.col + 3] == p.c)
			return (1);
	return (0);
}

int		check_down(char **b, int rows, int cols, t_choice p)
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
		if (	b[p.row + 1][p.col + 1] == p.c &&
				b[p.row + 2][p.col + 2] == p.c &&
				b[p.row + 3][p.col + 3] == p.c)
			return (1);
	return (0);
}

int		check_left_down(char **b, int rows, int cols, t_choice p)
{
	if (p.col - 3 < cols && p.row + 3 < rows && b[p.row][p.col] == ' ')
		if (	b[p.row + 1][p.col - 1] == p.c &&
				b[p.row + 2][p.col - 2] == p.c &&
				b[p.row + 3][p.col - 3] == p.c)
			return (1);
	return (0);
}

int		check_right_up(char **b, int rows, int cols, t_choice p)
{
	if (p.col + 3 < cols && p.row - 3 < rows && b[p.row][p.col] == ' ')
		if (	b[p.row - 1][p.col + 1] == p.c &&
				b[p.row - 2][p.col + 2] == p.c &&
				b[p.row - 3][p.col + 3] == p.c)
			return (1);
	return (0);
}

int		check_left_up(char **b, int rows, int cols, t_choice p)
{
	if (p.col - 3 < cols && p.row - 3 < rows && b[p.row][p.col] == ' ')
		if (	b[p.row - 1][p.col - 1] == p.c &&
				b[p.row - 2][p.col - 2] == p.c &&
				b[p.row - 3][p.col - 3] == p.c)
			return (1);
	return (0);
}

int		row_to_col(char **b, int rows, int col)
{
	while (rows-- >= 0)
		if (b[rows][col] == ' ')
			return (rows);
	return(0);
}

int		one_step_to_win(char **board, int rows, int cols)
{
	t_choice pos;

	pos.col = 0;
	pos.c = 'O';
	while (pos.col < cols)
	{
		pos.row = row_to_col(board, rows, pos.col);
		if (	check_right(board, rows, cols, pos) ||
				check_down(board, rows, cols, pos) ||
				check_left_down(board, rows, cols, pos) ||
				check_left_up(board, rows, cols, pos) ||
				check_right_down(board, rows, cols, pos) ||
				check_right_up(board, rows, cols, pos))
		{
			board[pos.row][pos.col] = 'O';
			return (1);
		}
		pos.col++;
	}
	return (0);
}

int			stop_winer(char **board, int rows, int cols)
{
	t_choice pos;

	pos.col = 0;
	pos.c = 'O';
	while (pos.col < cols)
	{
		pos.row = row_to_col(board, rows, pos.col);
		if (	check_right(board, rows, cols, pos) ||
				check_down(board, rows, cols, pos) ||
				check_left_down(board, rows, cols, pos) ||
				check_left_up(board, rows, cols, pos) ||
				check_right_down(board, rows, cols, pos) ||
				check_right_up(board, rows, cols, pos))
		{
			board[pos.row][pos.col] = 'X';
			return (1);
		}
		pos.col++;
	}
	return (0);
}
/*
int		one_step_for_win(char **board, int rows, int cols, t_choice *pos)
{
	pos->col = 0;
	while (pos->col < cols)
	{
		pos->row = row_to_col(board, rows, pos->col);
		if (	check_right(board, rows, cols, pos) ||
				check_down(board, rows, cols, pos) ||
				check_left_down(board, rows, cols, pos) ||
				check_left_up(board, rows, cols, pos) ||
				check_right_down(board, rows, cols, pos) ||
				check_right_up(board, rows, cols, pos))
		{
			return (1);
		}
		pos->col++;
	}
	return (0);
}
*/

int			get_score(char **board, int rows, int cols, t_choice pos)
{
	int connects;
	int score;
	int i;

	score = 0;
	i = 1;
	connects = 0;
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
	score = (connects > score) ? (connects) : (score);
	i = 1;
	connects = 0;
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
	score = (connects > score) ? (connects) : (score);
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
	score = (connects > score) ? (connects) : (score);
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
	score = (connects > score) ? (connects) : (score);
	return (score);
}

int			best_position(char **board, int rows, int cols)
{
	t_choice pos;
	int col;
	int score;

	pos.col = 0;
	col = 0;
	score = 0;
	while (pos.col < cols)
	{
		pos.row = row_to_col(board, rows, pos.col);
		pos.c = 'O';
		if (score < get_score(board, rows, cols, pos))
			col = pos.col;
		pos.col++;
	}
	return (col);
}

void		ft_ai_player(char **board, int rows, int cols)
{
	t_choice pos;
	int col;
	int row;

	col = 0;
	while (col < cols)
		if (board[rows - 1][col++] != ' ')
			break;
	if (col == cols && board[rows - 1][cols - 1] == ' ')
	{
		board[rows - 1][cols / 2] = 'O';
		ft_print_board(board, rows, cols);
		return ;
	}
	if (one_step_to_win(board, rows, cols))
	{
		ft_print_board(board, rows, cols);
		return ;
	}
	if (stop_winer(board, rows, cols))
	{	
		ft_print_board(board, rows, cols);
		return ;
	}
	col = best_position(board, rows, cols);
	row = row_to_col(board, rows, col);
	board[row][col] = 'O';
	ft_print_board(board, rows, cols);
}
