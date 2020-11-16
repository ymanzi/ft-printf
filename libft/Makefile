# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 14:05:13 by ymanzi            #+#    #+#              #
#    Updated: 2019/11/27 20:57:55 by ymanzi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_atoi.c ft_putnbr_base_fd.c ft_strlen.c \
ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_isdigit.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
clean:
		rm -f $(OBJ) $(OBJ_B)
fclean: clean
		rm -f $(NAME)
re: fclean all

.PHONY:all fclean re
