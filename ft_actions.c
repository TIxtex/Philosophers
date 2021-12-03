#include "philosofers.h"

void	ft_slepping(t_philo *philo)
{
	if (ft_dead_check(philo))
		printf("%f	-	%d is sleeping\n", ft_time_diff(philo->dat->i_time, philo->aux_time), philo->philo_id);
	philo->aux_time = ft_wait_time(philo->aux_time, ft_usec(philo->dat->time_to_sleep));
}

void	ft_thinking(t_philo *philo)
{
	if(ft_dead_check(philo))
		printf("%f	-	%d is thinking\n", ft_time_diff(philo->dat->i_time, philo->aux_time), philo->philo_id);
}
