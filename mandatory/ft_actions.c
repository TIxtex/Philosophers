#include "../philosofers.h"

void	ft_slepping(t_philo *philo)
{
	if (ft_dead_check(philo))
		printf("%f	-	%d is sleeping\n", ft_time_diff(&philo->dat->i_time, &philo->aux_time), philo->philo_id);
	philo->aux_time = ft_wait_time(philo->aux_time, ft_traslate_usec(philo->dat->time_to_sleep));
}

void	ft_thinking(t_philo *philo)
{
	if(ft_dead_check(philo))
		printf("%f	-	%d is thinking\n", ft_time_diff(&philo->dat->i_time, &philo->aux_time), philo->philo_id);
}

void	*ft_take_forks(t_philo *philo, int first, int second)
{
	if (pthread_mutex_lock(&philo->dat->mutex[first]))
		return (NULL);
	if (ft_dead_check(philo))
		printf("%f	-	%d has taken a fork\n", ft_time_diff(&philo->dat->i_time, &philo->aux_time), philo->philo_id);
	if (pthread_mutex_lock(&philo->dat->mutex[second]))
		return (NULL);
	if (ft_dead_check(philo))
		printf("%f	-	%d has taken a fork\n", ft_time_diff(&philo->dat->i_time, &philo->aux_time), philo->philo_id);
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
