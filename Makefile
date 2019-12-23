# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaach <amaach@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/29 09:43:16 by amaach            #+#    #+#              #
#    Updated: 2019/12/22 18:52:57 by amaach           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -c

SRCS = ft_atoi.c ft_check.c ft_initialisation.c ft_isdigit.c ft_itoa.c \
		ft_printf.c ft_putchar.c ft_puthexa_compt.c ft_putstr.c \
		ft_putnbr_prec.c ft_strdup.c ft_strlen.c ft_strrev.c ft_traitement.c \
		ft_traitement_adresse.c ft_traitement_adresse2.c ft_traitement_char.c \
		ft_traitement_hexa.c ft_traitement_hexa2.c ft_traitement_int.c \
		ft_traitement_int2.c ft_traitement_str.c ft_traitement_str2.c \
		ft_traitement_u.c ft_traitement_u2.c ft_putnbr_compt.c

$(NAME): all

all:
	gcc $(FLAGS) $(SRCS)
	ar -rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean
	make all
