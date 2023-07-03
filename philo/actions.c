#include "philosofers.h"

int	ft_write(t_philo *philo, char *msg)
{
	if (pthread_mutex_lock(&philo->dat->write_mutex))
		return (EXIT_FAILURE);
	printf("%ld	-	%d %s\n", time_diff(philo->dat->i_time, now_time()), philo->philo_id, msg);
	if (pthread_mutex_unlock(&philo->dat->write_mutex))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	slepping(t_philo *philo)
{
	if (ft_write(philo, "is sleeping"))
		return (EXIT_FAILURE);
	wait_time(philo->dat->time_to_sleep);
	return (EXIT_SUCCESS);
}

int	thinking(t_philo *philo)
{
	if (ft_write(philo, "is thinking"))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
