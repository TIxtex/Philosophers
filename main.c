#include "philosofers.h"

int	ft_patrol(t_philo *philos)
{
	int	i;

	i = 0;
	while (i++ < philos->dat->p_num)
	{
		if (ft_traslate_usec(philos->dat->time_to_death) < ft_time_diff(philos[i].last_eat, philos[i].aux_time))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	dat;
	t_philo	*philos;

	if (ft_check_arg(argc, argv))
		return (-1);
	ft_asing_arg(&dat, argc, argv);
	if (ft_mutex_create(&dat))
		return (-1);
	philos = NULL;
	if (ft_thread_create(&dat, philos))
		return (-1);
	sleep(2);
	while (ft_patrol(philos))
		;
//posible blucle de detuchs
	printf("Fin de la ejecución\n");/**/
	free(dat.mutex);
	return (0);
}
