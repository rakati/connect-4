/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <nouhaddo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:36:52 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/12/23 23:07:13 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H 
# define PUISSANCE4_H

# define WHITE(x) "\033[37;1m" x "\033[0m"
# define RED(x) "\033[31;1m" x "\033[0m"
# define YELLOW(x) "\033[33;1m" x "\033[0m"

#include "libft/libft.h"
#include <time.h>
#include <sys/types.h>
#include <sys/uio.h>

void	ft_print_line(int len);
void	ft_print_numbers(int cols);
void	ft_print_board(char **board, int rows, int cols);
char	**initializeBoard(int rows, int cols);

/*
** rules 
*/

int		ft_valid_choice(int choice, char **board, int rows, int cols);
char	ft_check_winer(char **board, int rows, int cols);
int		ft_finished(char **board, int cols);
void	ft_player(char **board, int rows, int cols);
char	play_loop(char **board, int rows, int cols);

/*
** struct
*/
typedef struct s_choice
{
	int			col;
	int			row;
	char		c;
}				t_choice;

void	ft_ai_player(char **board, int rows, int cols);

/*
** tools1
*/

int		check_right(char **b, int cols, t_choice p);
int		check_down(char **b, int rows, t_choice p);
int		check_right_down(char **b, int rows, int cols, t_choice p);
int		check_left_down(char **b, int rows, int cols, t_choice p);
int		check_right_up(char **b, int rows, int cols, t_choice p);

/*
** tools2
*/

int		get_score(char **board, int rows, int cols, t_choice pos);

/*
** ft_ai_player
*/

void	ft_ai_player(char **board, int rows, int cols);

/*
** ai_medium
*/

int		check_left_up(char **b, int rows, int cols, t_choice p);
int		row_to_col(char **b, int rows, int col);
int		one_step_to_win(char **board, int rows, int cols);
int		stop_winer(char **board, int rows, int cols);
int		best_position(char **board, int rows, int cols);

#endif