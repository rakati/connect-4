/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:36:52 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/12/09 20:59:24 by nouhaddo         ###   ########.fr       */
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

void	ft_putwchar(int c);
void	ft_print_usage(void);
void	ft_print_line(int len);
void	ft_print_board(char **board, int rows, int cols);
char	**initializeBoard(int rows, int cols);

/*
** rules 
*/

int		ft_valid_choice(int choice, char **board, int rows, int cols, char p);
char	ft_check_winer(char **board, int rows, int cols);
int		ft_finished(char **board, int rows, int cols);
char	ft_play_with_omar(char **board, int rows, int cols);

#endif
