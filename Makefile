# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 16:08:05 by cschmied          #+#    #+#              #
#    Updated: 2023/04/22 18:14:47 by cschmied         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH		:= sources:sources/utils

UTILS		:= ft_putstr.c ft_atoi.c ft_calloc.c

SRCS		:= philo.c info_init.c gettime.c $(UTILS)

OBJS		:= $(SRCS:.c=.o)

CFLAGS		:= -Wall -Werror -Wextra -O2 -g

LDFLAGS		:= $(CFLAGS) -lpthread

NAME		:= philo

CC			:= cc

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re all valgrind

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

all: $(NAME)

re: fclean all

valgrind: $(NAME)
	valgrind -s --leaks-check=full --track-origin=yes ./philo 10 50 5 10
