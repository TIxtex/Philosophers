#include "../philosofers.h"

void	ft_asing_arg(t_data *dat, int argc, char **argv)
{
	dat->p_num = (int)ft_atoi(argv[1]);
	dat->time_to_death = (int)ft_atoi(argv[2]);
	dat->time_to_eat = (int)ft_atoi(argv[3]);
	dat->time_to_sleep = (int)ft_atoi(argv[4]);
	if (6 == argc)
		dat->must_eat = (int)ft_atoi(argv[5]);
	else
		dat->must_eat = -1;
	dat->dead = 0;
}

static int	ft_check_argv(char *argv)
{
	while (*argv)
	{
		if (!((unsigned)*argv - '0' < 10))
			return (1);
		argv++;
	}
	return (0);
}

int	ft_check_arg(int argc, char **argv)
{
	if (argc < 5)
		;
	else if (argc > 6)
		;
	else if (ft_check_argv(argv[1]))
		;
	else if (ft_check_argv(argv[2]))
		;
	else if (ft_check_argv(argv[3]))
		;
	else if (ft_check_argv(argv[4]))
		;
	else if (6 == argc && ft_check_argv(argv[5]))
		;
	else
		return (0);
	write(STDERR_FILENO, "Error\n", 6);
	return (1);
}
