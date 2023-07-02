#include "philosofers.h"

int dead_door(t_philo *philo)
{
	int i;

	i = 1;
	pthread_mutex_lock(&philo->dat->dead_mutex);
	if (1 == philo->dat->dead)
		i = 0;
	pthread_mutex_unlock(&philo->dat->dead_mutex);
	return(i);
}
