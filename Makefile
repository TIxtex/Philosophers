NAME = philo
SOURCES = ft_libft.c ft_check_arg.c ft_time.c ft_dead.c\
	ft_mutex.c ft_pthread.c ft_actions.c main.c
OBJECT = $(SOURCES:.c=.o)
COMPILER = gcc
FLAGS = -Wall -Wextra -Werror
THR = -lpthread

.PHONY: all clean fclean f re

all: $(NAME)
$(NAME): $(SOURCES)
	$(COMPILER) $(FLAGS) -c $(SOURCES)
	$(COMPILER) $(OBJECT) $(THR) -o $(NAME)
clean:
	/bin/rm -rf $(OBJECT)
fclean: clean
	/bin/rm -rf $(NAME)
f: fclean
re: fclean all
