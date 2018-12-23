/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ai_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <nouhaddo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:16:40 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/12/23 23:33:51 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"



char		ft_check_winer(char **b, int rows, int cols)
{
	int		c;
	int		r;

	r = 0;
	while (r < rows)
	{
		c = 0;
		while (c < cols)
		{
			if (c + 3 < cols && b[r][c] != ' ')
				if (b[r][c] == b[r][c + 1] && b[r][c + 1] == b[r][c + 2] &&
						b[r][c + 2] == b[r][c + 3])
					return (b[r][c]);
			if (r + 3 < rows && b[r][c] != ' ')
				if (b[r][c] == b[r + 1][c] && b[r + 1][c] == b[r + 2][c] &&
						b[r + 2][c] == b[r + 3][c])
					return (b[r][c]);
			if ((r + 3) < rows && (c + 3) < cols && b[r][c] != ' ')
				if (b[r][c] == b[r + 1][c + 1] && b[r][c] == b[r + 2][c + 2] &&
						b[r][c] == b[r + 3][c + 3])
					return (b[r][c]);
			if (r + 3 <= rows && c - 3 >= 0 && b[r][c] != ' ')
				if (b[r][c] == b[r + 1][c - 1] && b[r][c] == b[r + 2][c - 2] &&
						b[r][c] == b[r + 3][c - 3])
					return (b[r][c]);
            c++;
		}
        r++;
	}
	return ('\0');
}

void		ft_ai_player(char **board, int rows, int cols)
{
	int		col;

	col = 0;
	while (col < cols)
		if (board[rows - 1][col++] != ' ')
			break ;
	if (col == cols && board[rows - 1][cols - 1] == ' ')
		board[rows - 1][cols / 2] = 'O';
	else if (one_step_to_win(board, rows, cols))
		col = 0;
	else if (stop_winer(board, rows, cols))
		col = 0;
	else
	{
		col = best_position(board, rows, cols);
		board[row_to_col(board, rows, col)][col] = 'O';
	}
	ft_print_board(board, rows, cols);
}
