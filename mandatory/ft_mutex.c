#include "../philosofers.h"

int	ft_mutex_create(t_data *dat)
{
	int	i;

	i = 0;
	if (1 == dat->p_num)
		i = 1;
	dat->mutex = (pthread_mutex_t *)malloc(
			(dat->p_num + i) * sizeof(pthread_mutex_t));
	if (NULL == dat->mutex)
		return (1);
	i += dat->p_num;
	while (i-- > 0)
		if (-1 == pthread_mutex_init(&dat->mutex[i], NULL))
			return (1);
	return (0);
}

int	ft_thread_create(t_data *dat)
{
	int	i;

	i = -1;
	dat->philo = (pthread_t *)malloc(dat->p_num * sizeof(pthread_t));
	if (NULL == dat->philo)
		return (1);
	while (++i < dat->p_num)
		if (0 != pthread_create(&dat->philo[i], NULL, &ft_pthread_handler, dat))
			return (1);
	while (--i >= 0)
		if (0 != pthread_join(dat->philo[i], NULL))
			return (1);
	return (0);
}
