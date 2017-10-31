# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schevall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 10:27:19 by schevall          #+#    #+#              #
#    Updated: 2017/03/17 12:50:01 by schevall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Wextra -Werror
SRCS_NAME = ft_atoi.c\
	  ft_abs.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_bzero.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_isspace.c\
	  ft_lstadd.c\
	  ft_lstiter.c\
	  ft_lstdelone.c\
	  ft_lstdel.c\
	  ft_memalloc.c\
	  ft_itoa.c\
	  ft_lstnew.c\
	  ft_memchr.c\
	  ft_memccpy.c\
	  ft_lstmap.c\
	  ft_memcmp.c\
	  ft_memdel.c\
	  ft_memcpy.c\
	  ft_putchar.c\
	  ft_putchar_fd.c\
	  ft_putendl.c\
	  ft_putendl_fd.c\
	  ft_memset.c\
	  ft_memmove.c\
	  ft_putstr.c\
	  ft_putnbr.c\
	  ft_putstr_fd.c\
	  ft_putnbr_fd.c\
	  ft_strcat.c\
	  ft_strclr.c\
	  ft_strchr.c\
	  ft_strcmp.c\
	  ft_strdel.c\
	  ft_strcpy.c\
	  ft_striter.c\
	  ft_strdup.c\
	  ft_strndup.c\
	  ft_strequ.c\
	  ft_striteri.c\
	  ft_strjoin.c\
	  ft_strnjoin.c\
	  ft_strjoin_free.c\
	  ft_strlen.c\
	  ft_strlcat.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strncat.c\
	  ft_strncpy.c\
	  ft_strncmp.c\
	  ft_strnew.c\
	  ft_strnstr.c\
	  ft_strnequ.c\
	  ft_strrchr.c\
	  ft_strstr.c\
	  ft_strsub.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  ft_strtrim.c\
	  ft_strsplit.c\
	  ft_strsplit_whitespace.c\
	  get_next_line.c\
	  ft_power.c\
	  ft_nbrlen.c\
	  ft_strcnew.c\
	  ft_strupcase.c\
	  ft_sort_params.c\
	  ft_strdup_tab.c\
	  ft_tablen.c\
	  ft_strdel_tab.c\
	  ft_count_word.c\
	  ft_count_word_whitespace.c\
	  ft_word_len.c\
	  ft_word_len_whitespace.c\
	  ft_strndup_tab.c\
	  ft_printf_tab.c\
	  ft_strdup_free.c\
	  ft_supress_quote.c\

SRC_PATH = srcs/
SRCS = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_NAME = $(SRCS_NAME:.c=.o)
OBJ_PATH = obj/
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

INC = -I ./includes/

.PHONY: all, clean, fclean, re

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@make -C ./printf/

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p obj
	@gcc -c $(FLAG) $(INC) $< -o $@

clean:
	@make clean -C ./printf/
	@/bin/rm -rf $(OBJ)

fclean: clean
	@make fclean -C ./printf/
	@/bin/rm -f $(NAME)

re: fclean all
