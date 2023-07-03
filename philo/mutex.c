#include "philosofers.h"

int	mutex_create(t_data *dat)
{
	int	i;

	dat->fork_mutex = (pthread_mutex_t *)malloc(
			dat->p_num * sizeof(pthread_mutex_t));
	if (NULL == dat->fork_mutex)
		return (EXIT_FAILURE);
	i = dat->p_num;
	while (i-- > 0)
		if (pthread_mutex_init(&dat->fork_mutex[i], NULL))
			return (EXIT_FAILURE);
	if (pthread_mutex_init(&dat->write_mutex, NULL))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

t_philo	*thread_create(t_data *dat, t_philo *philos)
{
	int	i;

	i = -1;
	philos = (t_philo *)malloc(dat->p_num * sizeof(t_philo));
	if (NULL == philos)
		return (NULL);
	dat->philos = philos;
	dat->i_time = now_time();
	while (++i < dat->p_num)
	{
		philos[i].philo_id = i + 1;
		philos[i].dat = dat;
		if (pthread_create(&philos[i].philo,
			NULL, &pthread_handler, (void *)&philos[i]))
			return (NULL);
		else
			philos[i].last_eat = now_time();
	}
	return (philos);
}
