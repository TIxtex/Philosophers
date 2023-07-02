#include "philosofers.h"

void	ft_write(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->dat->write_mutex);
	printf("%lld	-	%d %s\n", time_diff(philo->dat->i_time, now_time()), philo->philo_id, msg);
	pthread_mutex_unlock(&philo->dat->write_mutex);
}

void	slepping(t_philo *philo)
{
	if (dead_door(philo))
		ft_write(philo, "is sleeping");
	wait_time(philo->dat->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	if(dead_door(philo))
		ft_write(philo, "is thinking");
}
