# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/22 16:20:25 by rgwayne-          #+#    #+#              #
#    Updated: 2020/01/13 13:49:40 by bjasper          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = *.c

INCL = printf.h

GCC_FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c
	gcc $(GCC_FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all