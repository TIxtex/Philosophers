NAME = philo
COMPILER = gcc -std=c89
FLAGS = -Wall -Wextra -Werror -pedantic
THR = -lpthread
INCLUDES = philosofers.h
SOURCES = libft.c check_arg.c time.c dead.c\
	mutex.c pthread.c actions.c eat.c\
	main.c
OBJECT = $(SOURCES:.c=.o)

.PHONY: all clean fclean f re

all: $(NAME)
$(NAME): $(SOURCES) $(INCLUDES)
	$(COMPILER) $(FLAGS) -c $(SOURCES)
	$(COMPILER) $(OBJECT) $(THR) -o $(NAME)
clean:
	/bin/rm -rf $(OBJECT)
fclean: clean
	/bin/rm -rf $(NAME)
f: fclean
re: fclean all
