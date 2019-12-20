# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaach <amaach@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/29 09:43:16 by amaach            #+#    #+#              #
#    Updated: 2019/12/20 15:01:19 by amaach           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

FLAGS = -Wall -Wextra -Werror -c

SRCS = *.c				\

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
