#include "philosofers.h"


void	ft_write(t_philo philo, char *msg)
{
	pthread_mutex_lock(philo.dat.write_mutex);
	printf("%f	-	%d %s\n", ft_time_diff(philo->dat->i_time, philo->aux_time), philo->philo_id, msg);
	pthread_mutex_unlock(philo.dat.write_mutex);
}

void	ft_slepping(t_philo *philo)
{
	if (ft_dead_door(philo))
		ft_write(philo, "is sleeping");
	philo->aux_time = ft_wait_time(philo->aux_time, ft_usec(philo->dat->time_to_sleep));
}

void	ft_thinking(t_philo *philo)
{
	if(ft_dead_door(philo))
		ft_write(philo, "is thinking");
}
