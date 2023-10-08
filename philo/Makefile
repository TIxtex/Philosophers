NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
THR = -lpthread
DEBUG = -fsanitize=thread

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


ARGS = 2 600 200 200 2

.PHONY: all clean fclean f re run debug

$(NAME): $(OBJECTS) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJECTS) $(THR) -o $(NAME)

debug: $(OBJECTS) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJECTS) $(THR) $(DEBUG) -o $(NAME)
	
all: $(NAME)
clean:
	/bin/rm -rf $(OBJECTS)
fclean: clean
	/bin/rm -rf $(NAME)
re: fclean all
f: fclean
run:
	./$(NAME) $(ARGS)