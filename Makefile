# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schevall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/06 16:45:19 by schevall          #+#    #+#              #
#    Updated: 2017/10/23 18:05:12 by schevall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./players/schevall.filler
FLAGS = -Wall -Wextra -Werror
SRC_NAME = main.c\
			parse_grid.c\
			parse_piece.c\
			error_handler.c\
			printer.c

SRC_PATH = ./srcs/
SRCS = $(addprefix $(SRC_PATH), $(SRCS_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./srcs/obj/
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

INC = -I ./srcs/includes/ -I ./srcs/libft/
LIB = -L ./srcs/libft/ -lft -L ./srcs/libft/printf/ -lftprintf

.PHONY: all, clean, fclean, re

$(NAME): $(OBJ)
	@make -C ./srcs/libft/
	gcc $(FLAGS) $(INC) $(LIB) -o $(NAME) $(OBJ)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p ./srcs/obj
	@gcc -c -g $(FLAG) $(INC) -o $@ $<

clean:
	@make clean -C ./srcs/libft/
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@make fclean -C ./srcs/libft/
	@/bin/rm -f $(NAME)

re: fclean all
