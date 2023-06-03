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
BUILDDIR	:= build

UTILS		:= ft_atoi.c ft_calloc.c ft_wait.c print_messages.c \
				free_resources.c ft_isint.c

SRCS		:= main.c philo.c info_init.c ft_gettime.c check_state.c $(UTILS)

OBJS		:= $(SRCS:%.c=$(BUILDDIR)/%.o)

CFLAGS		:= -Wall -Werror -Wextra -g  -I ./includes

LDFLAGS		:= $(CFLAGS) -lpthread -g -I ./includes

NAME		:= philo

CC			:= cc

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

$(BUILDDIR)/%.o: %.c $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR):
	@mkdir $(BUILDDIR)

.PHONY: clean fclean re all valgrind test

clean:
	@rm -f $(OBJS)
	@rm -rf $(BUILDDIR)

fclean: clean
	rm -f $(NAME)

all: $(NAME)

re: fclean all

test: re
	./$(NAME) 4 410 200 200

valgrind: $(NAME)
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./philo 1 400 210 200
