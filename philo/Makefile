# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 12:07:17 by cschmied          #+#    #+#              #
#    Updated: 2023/04/12 15:28:19 by cschmied         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= philo

VPATH		:= sources:sources/utils:sources/philo_utils

UTILS		:= ft_atoi.c ft_putnbr.c ft_putstr.c
PHILO_UTILS	:= try_clean.c check_for_dead.c
SOURCES		:= $(PHILO_UTILS) $(UTILS) main.c inits.c
OBJS		:= $(SOURCES:.c=.o)

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g -O2

MAKE		:= make
MAKEFLAGS	:= --no-print-directory --warn-undefined-variables --silent

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
