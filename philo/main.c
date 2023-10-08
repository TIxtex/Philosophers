#include "philosofers.h"

static void free_all(t_data dat, t_philo *philos)
{
	int i;

	i = -1;
	sleep(1);
	while (++i < dat.p_num)/*PROD*/
	{
		pthread_mutex_destroy(&dat.fork_mutex[i]);
		pthread_mutex_destroy(dat.philos[i].last_eat.mutex_var);
	}
	pthread_mutex_destroy(&dat.write_mutex);
	pthread_mutex_destroy(dat.finish.mutex_var);
	free(dat.fork_mutex);
	if (NULL != philos)
		free(philos);
}

static void	asing_arg(t_data *dat, int argc, char **argv)
{
	dat->finish.var = ZERO;
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
	size_t	i;

	if (10 < ft_strlen(argv))
		return (EXIT_FAILURE);
	i = ZERO;
	while (argv[i])
	{
		if (!((unsigned)argv[i] - '0' < 10))
			return (EXIT_FAILURE);
		i++;
	}
	i = ft_atoi(argv);
	return (INT_MAX < i);
}

static int	check_arg(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		;
	else if (check_argv(argv[1])
		|| check_argv(argv[2])
		|| check_argv(argv[3])
		|| check_argv(argv[4]))
		;
	else if (6 == argc && check_argv(argv[5]))
		;
	else
		return (EXIT_SUCCESS);
	return (write(STDERR_FILENO, "Error ARGS\n", 11));
}

int		main(int argc, char **argv)
{
	t_data	dat;
	t_philo	*philos;

	philos = NULL;
	if (check_arg(argc, argv))
		return (EXIT_FAILURE);
	if (asing_arg(&dat, argc, argv), mutex_create(&dat))
		return (errno);
	philos = thread_create(&dat, philos);
	if (NULL == philos)
		return (free_all(dat, NULL), EXIT_FAILURE);
	if (patrol(philos))
		return (free_all(dat, philos), EXIT_FAILURE);
	return (free_all(dat, philos), EXIT_SUCCESS);
}
