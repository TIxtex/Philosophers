#include "../philosofers.h"

int	ft_starve(t_philo *philo)
{
	if (ft_traslate_usec(philo->dat->time_to_death) < ft_time_diff(&philo->last_eat, &philo->dat->aux_time))
		return (1);
	return (0);
}

int	ft_dead_check(t_philo *philo)
{
//	philo->dat->aux_time = ft_wait_time(philo->dat->aux_time, 0);//refress aux_time
	if (philo->dat->dead)
		return (0);
	else if (ft_starve(philo))
	{
		philo->dat->dead = 1;
		printf("%f	-	%d died\n", ft_time_diff(&philo->dat->i_time, &philo->dat->aux_time), philo->philo_id);
		return (0);
	}
	return (1);
}
