#include "philosofers.h"

void	patrol(t_philo *philos)
{
	int	flag;
	int	i;

	flag = 1;
	while (flag)
	{
		i = -1;
		while (++i < philos->dat->p_num)
		{
			pthread_mutex_lock(&philos->dat->dead_mutex);
			if (philos->dat->time_to_death <= time_diff(philos[i].last_eat , now_time()))
			{
				flag = 0;
				philos->dat->dead = 1;
				ft_write(philos, "Fin de la simulación");//
				i = philos->dat->p_num;
			}
			pthread_mutex_unlock(&philos->dat->dead_mutex);
		}
	}
}

int		main(int argc, char **argv)
{
	t_data	dat;
	t_philo	*philos;

	philos = NULL;
	if (check_arg(argc, argv))
		return (-1);
	asing_arg(&dat, argc, argv);
	if (mutex_create(&dat))
		return (-1);
	philos = thread_create(&dat, philos);
	if (NULL == philos)
		return (-1);
	printf("Inicio Patrol\n");/*Debug*/
	patrol(philos);
	/*posible blucle de detuchs*/
	printf("Fin de la ejecución\n");/*Debug*/
	sleep(1);
	free(dat.fork_mutex);
	free(philos);
	return (0);
}
