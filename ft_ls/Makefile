# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpas <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/19 18:04:36 by mpas              #+#    #+#              #
#    Updated: 2018/11/30 19:55:20 by mpas             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CFLAGS = -Wall -Werror -Wextra
HEADER = includes/b_ls.h

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -I$(HEADER) main.c srcs/*.c utils/*.c b_printf/libftprintf.a -o $(NAME)

clean:

fclean: clean
	/bin/rm $(NAME)
re: fclean all
