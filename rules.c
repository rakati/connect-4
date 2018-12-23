/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <nouhaddo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:38:15 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/12/23 21:43:58 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		ft_valid_choice(int choice, char **board, int rows, int cols, char p)
{
	int row;
	if (choice < 0 || choice >= cols)
		return (0);
	row = rows - 1;
	while (row >= 0)
	{
		if (board[row][choice] == ' ')
		{
			board[row][choice] = p;
			return (1);
		}
		row--;
	}
	return (0);
}

char	ft_check_winer(char **b, int rows, int cols)
{
	int c;
	int r;

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

int		ft_finished(char **board, int rows, int cols)
{
	int pos;

	pos = 0;
	while (pos < cols)
		if (board[0][pos++] == ' ')
			return (0);
	return (1);
}
void	ft_player(char **board, int rows, int cols)
{
	char choice[10];
	int n;

	while (1)
	{
		ft_putstr("player: enter a column number : ");
		n = read(0, choice, 9);
		choice[n] = '\0';
		if(ft_valid_choice(ft_atoi(choice) - 1, board, rows, cols, 'X'))
			break;
		ft_putstr("not valid choice\n");
	}
	ft_print_board(board, rows, cols);
}
char	play_loop(char **board, int rows, int cols)
{
	int r;
	char s;

	srand(time(NULL));
	r = rand() % 100;
	if (r % 2 == 0)
		while (!ft_finished(board, rows, cols))
		{
			ft_player(board, rows, cols);
			if ((s = ft_check_winer(board, rows, cols)))
				return (s);
			ft_ai_player(board, rows, cols);
			if ((s = ft_check_winer(board, rows, cols)))
				return (s);
		}
	else
		while (!ft_finished(board, rows, cols))
		{
			ft_ai_player(board, rows, cols);
			if ((s = ft_check_winer(board, rows, cols)))
				return (s);
			ft_player(board, rows, cols);
			if ((s = ft_check_winer(board, rows, cols)))
				return (s);
		}
	return ('\0');
}