#include "philosofers.h"

static void	asing_arg(t_data *dat, int argc, char **argv)
{
	dat->dead = 0;
	dat->p_num = (int)ft_atoi(argv[1]);
	dat->time_to_death = (int)ft_atoi(argv[2]);
	dat->time_to_eat = (int)ft_atoi(argv[3]);
	dat->time_to_sleep = (int)ft_atoi(argv[4]);
	if (6 == argc)
		dat->must_eat = (int)ft_atoi(argv[5]);
	else
		dat->must_eat = -1;
	dat->fork_mutex = NULL;
}

static int	check_argv(char *argv)
{
	while (*argv)
	{
		if (!((unsigned)*argv - '0' < 10))
			return (1);
		argv++;
	}
	return (EXIT_SUCCESS);
}

static int	check_arg(int argc, char **argv)
{
	if (argc < 5)
		;
	else if (argc > 6)
		;
	else if (check_argv(argv[1]))
		;
	else if (check_argv(argv[2]))
		;
	else if (check_argv(argv[3]))
		;
	else if (check_argv(argv[4]))
		;
	else if (6 == argc && check_argv(argv[5]))
		;
	else
		return (EXIT_SUCCESS);
	write(STDERR_FILENO, "Error ARGS\n", 11);
	return (EXIT_FAILURE);
}

static void	patrol(t_philo *philos)
{
	int	flag;
	int	i;

	flag = 1;
	while (flag)
	{
		i = -1;
		while (++i < philos->dat->p_num)
		{
			
			if (philos->dat->time_to_death <= time_diff(philos[i].last_eat , now_time()))
			{
				pthread_mutex_lock(&philos->dat->dead_mutex);
				flag = 0;
				philos->dat->dead = 1;
				ft_write(philos, "Fin de la simulación");//
				i = philos->dat->p_num;
				pthread_mutex_unlock(&philos->dat->dead_mutex);
			}
		}
	}
}

int		main(int argc, char **argv)
{
	t_data	dat;
	t_philo	*philos;

	philos = NULL;
	if (check_arg(argc, argv))
		return (EXIT_FAILURE);
	asing_arg(&dat, argc, argv);
	if (mutex_create(&dat))
		return (EXIT_FAILURE);
	philos = thread_create(&dat, philos);
	if (NULL == philos)
		return (EXIT_FAILURE);
	printf("Inicio Patrol\n");/*Debug*/
	patrol(philos);
	/*posible blucle de joins*/
	printf("Fin de la ejecución\n");/*Debug*/
	sleep(1);
	free(dat.fork_mutex);
	free(philos);
	return (EXIT_SUCCESS);
}
