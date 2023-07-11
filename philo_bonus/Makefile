NAME = philo_bonus
CC = gcc
CFLAGS = -std=c89 -Wall -Wextra -Werror -pedantic
THR = -lpthread
INCLUDES = philosofers.h
SOURCES = \
	libft.c \
	time.c \
	semaphore.c \
	philos.c \
	actions.c \
	main.c
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean fclean f re

all: $(NAME)
$(NAME): $(OBJECTS) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJECTS) $(THR) -o $(NAME)
clean:
	/bin/rm -rf $(OBJECTS)
fclean: clean
	/bin/rm -rf $(NAME)
f: fclean
re: fclean all
