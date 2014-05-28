#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgaspail <mgaspail@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/18 16:17:49 by mgaspail          #+#    #+#              #
#    Updated: 2014/01/18 19:05:39 by mgaspail         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

SRC_C = main.c \
		mouse.c \
		ft_drw.c \
		ft_init_map.c \
		ft_create_map.c \
		moveline.c \
		pixel.c \
		ft_hook.c \
		init_drw.c \
		string.c \

SRC_O = $(SRC_C:.c=.o)

SRC_H = wolf.h

SRC_A = libft/libft.a

FLAG = -Wall -Wextra -Werror -g

LIB = -L./libft -lft -L/usr/X11/lib -lXext -lX11 -lmlx

all		: $(NAME)

$(NAME)	: $(SRC_O)
		make -C libft/
		gcc $(FLAG) -O3 -o $(NAME) $^ $(LIB)

%.o: %.c
		gcc $(FLAG) -O3 -I libft/includes/ -c $<

clean	:
		make -C libft/ clean
		rm -f $(SRC_O)

fclean	: clean
		make -C libft/ fclean
		rm -f $(NAME)

re		: fclean all
