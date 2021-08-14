#include "../philosofers.h"

void	ft_slepping(t_philo *philo)
{
	printf("%lf	-	%d is sleeping\n", ft_time_diff(&philo->dat->i_time, &philo->dat->aux_time), philo->philo_id);
	ft_wait_time(philo, philo->dat->time_to_sleep);
}

void	ft_thinking(t_philo *philo)
{
	printf("%d	-	%d is thinking\n", ft_time_diff(&philo->dat->i_time, &philo->dat->aux_time), philo->philo_id);
	ft_wait_time(philo, philo->dat->time_to_death);
}

void	ft_dead(t_philo *philo)
{
	printf("%d	-	%d died\n", ft_time_diff(&philo->dat->i_time, &philo->dat->aux_time), philo->philo_id);
//	pthread_detach(dat->philos[dat->philos->philo_id - 1].philo);
}

void	*ft_take_forks(t_philo *philo, int first, int second)
{
	if (pthread_mutex_lock(&philo->dat->mutex[first]))
		return (NULL);
	printf("%d	-	%d has taken a fork\n", ft_time_diff(&philo->dat->i_time, &philo->dat->aux_time), philo->philo_id);
	if (pthread_mutex_lock(&philo->dat->mutex[second]))
		return (NULL);
	printf("%d	-	%d has taken a fork\n", ft_time_diff(&philo->dat->i_time, &philo->dat->aux_time), philo->philo_id);
	return (NULL);
}

void	*ft_leave_forks(t_philo *philo, int first, int second)
{
	if (pthread_mutex_unlock(&philo->dat->mutex[first]))
		return (NULL);
	if (pthread_mutex_unlock(&philo->dat->mutex[second]))
		return (NULL);
	return (NULL);
}
