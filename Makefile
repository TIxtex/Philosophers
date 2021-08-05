NAME = philo
SOURCESH = shared/ft_libft.c shared/ft_check_arg.c
SOURCESM = mandatory/ft_mutex.c
MAIN = mandatory/main.c
COMPILER = gcc
FLAGS = -Wall -Wextra -Werror
THR = -lpthread

.PHONY: all clean fclean f re

$(NAME): $(SOURCESC)
	$(COMPILER) $(FLAGS) $(SOURCESH) $(SOURCESM) $(MAIN) $(THR) -o $(NAME)
all: $(NAME)
clean:
	/bin/rm -rf $(OBJECTS)
fclean: clean
	/bin/rm -rf $(NAME)
f: fclean
re: fclean all
