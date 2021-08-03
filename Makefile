NAME = philo
SOURCES = shared/ft_libft.c shared/ft_check_arg.c
MAIN = main.c
COMPILER = gcc
FLAGS = -Wall -Wextra -Werror
THR = -lpthread

.PHONY: all clean fclean f re

$(NAME): $(SOURCESC)
	$(COMPILER) $(FLAGS) $(SOURCES) $(MAIN) $(THR) -o $(NAME)
all: $(NAME)
clean:
	/bin/rm -rf $(OBJECTS)
fclean: clean
	/bin/rm -rf $(NAME)
f: fclean
re: fclean all
