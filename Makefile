# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 14:05:13 by ymanzi            #+#    #+#              #
#    Updated: 2019/11/27 21:41:12 by ymanzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
SRCS = parsing_hexa.c parsing_uint.c parsing_int.c parsing_char.c \
parsing_string.c printf.c parsing_percent.c parsing_pointer.c printf2.c
LFT_SRC = libft
LIBFT = $(LFT_SRC)/libft.a

OBJ = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
		cp $(LFT_SRC)/libft.a $(NAME)
		ar rc $(NAME) $(OBJ)
$(LIBFT):
		(cd $(LFT_SRC) && $(MAKE))
clean:
		rm -f $(OBJ) 
		(cd $(LFT_SRC) && $(MAKE) $@)
fclean: clean
		rm -f $(NAME)
		(cd $(LFT_SRC) && $(MAKE) $@)
re: fclean all

.PHONY:all fclean re
