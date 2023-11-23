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
CFLAGS = -Wall -Wextra -Werror -pedantic -g3
THR = -lpthread
DEBUG = -fsanitize=thread -fsanitize=address

INCLUDES = philosofers.h
SOURCES = \
	libft.c \
	time.c \
	mutex.c \
	pthread.c \
	actions.c \
	eat.c \
	data_races.c \
	main.c
OBJECTS = $(SOURCES:.c=.o)

ARGS = 199 1000 200 200 2

.PHONY: all clean fclean f re run debug

$(NAME): $(OBJECTS) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJECTS) $(THR) -o $(NAME)

debug: $(OBJECTS) $(INCLUDES)
	$(CC) $(CFLAGS) $(DEBUG) $(OBJECTS) $(THR)  -o $(NAME)
	
all: $(NAME)
clean:
	/bin/rm -rf $(OBJECTS)
fclean: clean
	/bin/rm -rf $(NAME)
re: fclean all
f: fclean
run:
	./$(NAME) $(ARGS)