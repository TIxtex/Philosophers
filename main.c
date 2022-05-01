#include "philosofers.h"

void	ft_patrol(t_philo *philos)
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
			if (philos->dat->time_to_death <= ft_time_diff(philos[i].last_eat , ft_now_time()))
			{
				flag = 0;
				philos->dat->dead = 1;
				ft_write(philo, );
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
	if (ft_check_arg(argc, argv))
		return (-1);
	ft_asing_arg(&dat, argc, argv);
	if (ft_mutex_create(&dat))
		return (-1);
	philos = ft_thread_create(&dat, philos);
	if (NULL == philos)
		return (-1);
	printf("Inicio Patrol\n");/*Debug*/
	ft_patrol(philos);
//posible blucle de detuchs
	printf("Fin de la ejecución\n");/*Debug*/
	sleep(1);
	free(dat.fork_mutex);
	free(philos);
	return (0);
}
