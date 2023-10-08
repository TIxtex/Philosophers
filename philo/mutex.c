#include "philosofers.h"

int	mutex_create(t_data *dat)
{
	register int	i;

	dat->fork_mutex = (pthread_mutex_t *) malloc(
			dat->p_num * sizeof(pthread_mutex_t));
	if (NULL == dat->fork_mutex)
		return (errno);
	i = dat->p_num;
	while (i-- > 0)
		if (pthread_mutex_init(&dat->fork_mutex[i], NULL))
			return (errno);
	if (pthread_mutex_init(&dat->write_mutex, NULL))
		return (errno);
	if (pthread_mutex_init(&dat->finish.mutex_var, NULL))
		return (errno);
	return (EXIT_SUCCESS);
}

t_philo	*thread_create(t_data *dat, t_philo *philos)
{
	register int	i;

	i = -1;
	philos = (t_philo *) malloc(dat->p_num * sizeof(t_philo));
	if (NULL == philos)
		return (NULL);
	dat->philos = philos;
	dat->i_time = now_time();
	while (++i < dat->p_num)
	{
		philos[i].philo_id = i + 1;
		philos[i].dat = dat;
		philos[i].last_eat.var = now_time();/*DANGER*/
		if (pthread_mutex_init(&philos[i].last_eat.mutex_var, NULL))
			exit(errno);
		if (pthread_create(&philos[i].philo,
			NULL, &pthread_handler, (void *)&philos[i]))
			return (NULL);
	}
	return (philos);
}
