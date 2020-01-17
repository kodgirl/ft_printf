# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/22 16:20:25 by rgwayne-          #+#    #+#              #
#    Updated: 2020/01/16 20:06:07 by rgwayne-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
		parser.c \
		converser.c \
		string_maker.c \
		word_width_maker.c \
		ft_new_itoa.c \
		ft_flags.c \
		word_prec_maker.c \
		libft.c \
		ft_for_int.c \
		ft_long_itoa.c \
		ft_for_int2.c \
		ft_for_octal.c \
		ft_hex.c \
		parser2.c \
		ft_for_c.c \
		ft_for_s.c \
		ft_for_p.c \
		ft_for_f.c \
		ft_fractal.c \
		ft_float.c \
		ft_long_ariphm.c

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
