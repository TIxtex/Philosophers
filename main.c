#include "philosofers.h"

int	ft_starve(t_data dat)
{
	int	i;

	i = -1;
	while (++i < dat->p_num)
		if (ft_usec(dat->time_to_death) < ft_time_diff(dat->philo[i]->last_eat, ft_actual_time()))
			return (1);
	return (0);
}

void	ft_patrol(t_data *dat)
{
	int	i;

	i = 1;
	while (i)
	{
		sleep(1);
		pthread_mutex_lock(&philos->dat->dead_mutex);
		if (1 == philos->dat->dead)
			i = 0;
		else
			ft_starve(dat);
		pthread_mutex_unlock(&philos->dat->dead_mutex);
	}
}

int		main(int argc, char **argv)
{
	t_data	dat;
	t_philo	*philos;

	if (ft_check_arg(argc, argv))
		return (-1);
	ft_asing_arg(&dat, argc, argv);
	if (ft_mutex_create(&dat))
		return (-1);
	if (ft_thread_create(&dat, philos))
		return (-1);
//posible blucle de detuchs
	printf("Fin de la ejecución\n");/**/
	free(dat.fork_mutex);
	free(philos);
	return (0);
}
