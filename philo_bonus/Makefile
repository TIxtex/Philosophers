# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 20:13:02 by uliherre          #+#    #+#              #
#    Updated: 2023/10/19 20:49:36 by uliherre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -o3 -Wall -Wextra -Werror -pedantic
LDFLAGS = -lpthread
#DEBUG = -fsanitize=thread -fsanitize=address

INCLUDE = philosofers.h
SOURCES = \
	actions.c \
	libft.c \
	main.c \
	process.c

OBJECTS = $(SOURCES:.c=.o)

ARGS = 5 700 200 200 15

.PHONY: all clean fclean f re run

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

all: $(NAME)
clean:
	/bin/rm -rf $(OBJECTS)
fclean: clean
	/bin/rm -rf $(NAME)
re: fclean all
f: fclean
run:
	./$(NAME) $(ARGS)