#include "philosofers.h"


void	ft_write(t_philo *philo, char *msg)
{
	pthread_mutex_lock(philo->dat.write_mutex);
	printf("%f	-	%d %s\n", ft_time_diff(philo->dat->i_time, ft_now_time()), philo->philo_id, msg);
	pthread_mutex_unlock(philo->dat.write_mutex);
}

void	ft_slepping(t_philo *philo)
{
	if (ft_dead_door(philo))
		ft_write(philo, "is sleeping");
	ft_wait_time(ft_usec(philo->dat->time_to_sleep));
}

void	ft_thinking(t_philo *philo)
{
	if(ft_dead_door(philo))
		ft_write(philo, "is thinking");
}
