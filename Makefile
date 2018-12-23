# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/22 18:23:20 by nouhaddo          #+#    #+#              #
#    Updated: 2018/12/23 22:56:16 by nouhaddo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = rules.c\
	  main.c\
	  ai_medium.c\
	  tools1.c\
	  tools2.c\
	  ft_ai_player.c

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra
NAME = puissance4
LIBDIR = -L./libft
LIB = -lft
all: libft.a $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) ./libft/libft.a -o $(NAME)
	
libft.a:
	make -C ./libft
clean:
	make -C ./libft clean
	rm -rf $(OBJ)
fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)
re: fclean all
