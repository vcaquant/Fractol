# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/15 16:05:38 by vcaquant          #+#    #+#              #
#    Updated: 2016/11/15 16:05:40 by vcaquant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			fractol

SRC = 			sources/fractol.c

OBJ = 			fractol.o

HEADER =		./libft/libft.h

FINDLIBFT =		-Llibft

PT_A =			./libft/libft.a

FLAGS = 		-Wall -Wextra -Werror -g

LIBFT_DIR =		./libft/

CC = 			gcc

all:	comp_oth $(NAME)

comp_oth:
		@make fclean -C $(LIBFT_DIR)
		@make -C $(LIBFT_DIR)
		@make -C $(LIBX_DIR)

$(NAME):
		@clear
		@$(CC) $(FLAGS) -c $(SRC) $(HEADER)
		@echo "\033[0;32m✔︎ Compilation Done\033[0m"

clean:
		@clear
		@rm -f $(OBJ)
		@rm -f fdf.h.gch
		@make clean -C $(LIBFT_DIR)

fclean:	clean
		@clear
		@rm -f $(NAME)
		@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all, clean, fclean, re