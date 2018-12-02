# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpas <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 13:02:02 by mpas              #+#    #+#              #
#    Updated: 2018/09/19 17:32:44 by mpas             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
HEADER = libftprintf.h

CFILES = src/ft_itoa_base.c src/b_printf.c src/ft_putchar.c src/ft_putstr.c src/ft_strlen.c
OFILES = *.o

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -I$(HEADER) -c $(CFILES) 
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OFILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
