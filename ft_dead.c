#include "philosofers.h"

int	ft_starve(t_philo *philo)
{
	if (ft_traslate_usec(philo->dat->time_to_death) < ft_time_diff(philo->last_eat, philo->aux_time))
	{
//		printf("SAMUELTOComprobacion de starveo del philo->%d:%f\n",philo->philo_id , ft_time_diff(philo->last_eat, philo->aux_time));
		return (1);
	}
//	printf("Comprobacion de starveo del philo->%d:%f\n",philo->philo_id , ft_time_diff(philo->last_eat, philo->aux_time));
	return (0);
}

int	ft_dead_check(t_philo *philo)
{

	if (philo->dead)
		return (0);
	else if (ft_starve(philo))
	{
		philo->dead = 1;
		printf("%f	-	%d died\n", ft_time_diff(philo->dat->i_time, philo->aux_time), philo->philo_id);
		return (0);
	}
	return (1);
}
