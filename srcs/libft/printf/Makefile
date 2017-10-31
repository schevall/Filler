# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schevall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 10:34:27 by schevall          #+#    #+#              #
#    Updated: 2017/03/15 16:45:23 by schevall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAG = -Wall -Wextra -Werror

SRCS_NAME = ft_printf.c\
			ft_printf_fd.c\
			ft_sprintf.c\
	  format_tree.c\
	  format_for_signed.c\
	  tools_for_signed.c\
	  format_for_unsigned.c\
	  nbrlen_base.c\
	  tools_for_unsigned.c\
	  tools_for_pconv.c\
	  format_for_string.c\
	  format_for_char.c\
	  format_for_wchar.c\
	  format_for_wstring.c\
	  tools_for_wstring.c\
	  detect_conv_type.c\
	  get_arg_from_ap_list.c\
	  get_param.c\
	  is_params.c\

SRC_PATH = srcs/
SRCS = $(addprefix $(SRC_PATH), $(SRCS_NAME))

OBJ_NAME = $(SRCS_NAME:.c=.o)
OBJ_PATH = obj/
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

INC = -I includes/

.PHONY: all, clean, fclean, re

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p obj
	@gcc -c $(FLAG) $(INC) $< -o $@

clean:
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@/bin/rm -f $(NAME)

re : fclean all

