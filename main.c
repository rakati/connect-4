/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:49:05 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/12/09 21:36:39 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void	ft_print_usage(void)
{
	ft_putstr("usage : ./puissance4 rows columns\n");
	ft_putstr("          rows > 5    columns > 6\n");
}

void	ft_print_line(int len)
{
	while (len-- > 0)
		ft_putstr("+ - ");
	ft_putstr("+\n");
}

void	ft_print_board(char **board, int rows, int cols)
{
	int row;
	int col;

	row = 0;
	while (row < rows)
	{
		col = 0;
		ft_print_line(cols);
		while (col < cols)
		{
			ft_putstr("| ");
			if (board[row][col] != ' ')
				ft_putstr(board[row][col] == 'p' ? RED("X") : YELLOW("O"));	
			//ft_putwchar((board[row][col] == 'p') ? 9673 : 9680);
			else
				ft_putchar(' ');
			ft_putstr(" ");
			col++;
		}
		ft_putstr("|\n");
		row++;
	}
	ft_print_line(cols);
}

char		**initializeBoard(int rows, int cols)
{
	char **board;
	int i;
	int j;

	i = 0;
	board = (char**)malloc(rows * sizeof(char*));
	while (i < rows)
	{
		board[i] = (char*)malloc((cols + 1) * sizeof(char*));
		j = 0;
		while (j < cols)
			board[i][j++] = ' ';
		board[i++][j] = '\0';
	}
	return (board);
}

int		main(int ac, char **av)
{
	int rows;
	int cols;
	char **board;
	char s;

	if (ac == 3 && (rows = ft_atoi(av[1])) > 5 && (cols = ft_atoi(av[2])) > 6)
	{
		board = initializeBoard(rows, cols);
		ft_print_board(board, rows, cols);
		if ((s = ft_play_with_omar(board, rows, cols)))
		{
			ft_putstr("the player ");
			ft_putstr(s == 'p' ? " 1 is the winner\n" : " 2 is the winner\n");
		}
		else
			ft_putstr("Game over with Draw\n");
	}
	else
		ft_print_usage();
	return (0);
}
