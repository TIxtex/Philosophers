#include "philosofers.h"

int	ft_mutex_create(t_data *dat)
{
	int	i;

	i = 0;	
	if (1 == dat->p_num)
		i = 1;
	dat->fork_mutex = (pthread_mutex_t *)malloc(
			(dat->p_num + i) * sizeof(pthread_mutex_t));
	if (NULL == dat->fork_mutex)
		return (1);
	i += dat->p_num;
	while (i-- > 0)
		if (-1 == pthread_mutex_init(&dat->fork_mutex[i], NULL))
			return (1);
	if (-1 == pthread_mutex_init(&dat->dead_mutex, NULL))
		return (1);
	if (-1 == pthread_mutex_init(&dat->write_mutex, NULL))
		return (1);
	return (0);
}

int	ft_thread_create(t_data *dat, t_philo *philos)
{
	int	i;

	i = -1;
	philos = (t_philo *)malloc(dat->p_num * sizeof(t_philo));
	if (NULL == philos)
		return (1);
	dat->philos = philos;
	dat->i_time = ft_now_time(void);
	while (++i < dat->p_num)
	{
		philos[i].philo_id = i + 1;
		philos[i].dat = dat;
		
		if (0 != pthread_create(&philos[i].philo,
				NULL, &ft_pthread_handler, (void *)&philos[i]))
			return (1);
		else
			philos[i].last_eat = ft_now_time();
	}
	return (0);
}
