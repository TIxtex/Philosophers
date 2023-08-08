#include "philosofers.h"

int	ft_write(t_philo *philo, char *msg)
{
	if (pthread_mutex_lock(&philo->dat->write_mutex))
		return (errno);
	if (philo->dat->finish == philo->dat->p_num)
	{
		pthread_mutex_unlock(&philo->dat->write_mutex);
		pthread_detach(philo->philo);
		return (EXIT_SUCCESS);
	}
	else
		printf("%ld	-	%d %s\n", time_diff(philo->dat->i_time, now_time()), philo->philo_id, msg);
	return (pthread_mutex_unlock(&philo->dat->write_mutex));
}

int	slepping(t_philo *philo)
{
	if (ft_write(philo, "is sleeping"))
		return (errno);
	wait_time(philo->dat->time_to_sleep);
	return (EXIT_SUCCESS);
}

int	thinking(t_philo *philo)
{
	return (ft_write(philo, "is thinking"));
}
