/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <nouhaddo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:36:52 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/12/23 21:01:30 by nouhaddo         ###   ########.fr       */
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
void	ft_print_numbers(char **board, int rows, int cols);
void	ft_print_board(char **board, int rows, int cols);
char	**initializeBoard(int rows, int cols);

/*
** rules 
*/

int		ft_valid_choice(int choice, char **board, int rows, int cols, char p);
char	ft_check_winer(char **board, int rows, int cols);
int		ft_finished(char **board, int rows, int cols);
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

void		ft_ai_player(char **board, int rows, int cols);

#endif