NAME = philo
CC = gcc 
CFLAGS = -Wall -Wextra -Werror
THR = -lpthread
INCLUDES = philosofers.h
SOURCES = \
	libft.c \
	check_arg.c \
	time.c \
	dead.c \
	mutex.c \
	pthread.c \
	actions.c \
	eat.c\
	main.c
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean fclean f re

all: $(NAME)
$(NAME): $(OBJECTS) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJECTS) $(THR) -o $(NAME)
clean:
	/bin/rm -rf $(OBJECT)
fclean: clean
	/bin/rm -rf $(NAME)
f: fclean
re: fclean all
