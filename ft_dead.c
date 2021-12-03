#include "philosofers.h"

int	ft_starve(t_philo *philo)
{
	if (ft_usec(philo->dat->time_to_death) < ft_time_diff(philo->last_eat, philo->aux_time))
	{
//		printf("SAMUELTOComprobacion de starveo del philo->%d:%f\n",philo->philo_id , ft_time_diff(philo->last_eat, philo->aux_time));
		return (1);
	}
//	printf("Comprobacion de starveo del philo->%d:%f\n",philo->philo_id , ft_time_diff(philo->last_eat, philo->aux_time));
	return (0);
}

int ft_dead_door(t_philo *philo)
{
	int i;

	i = 0;
	pthread_mutex_lock(&philo->dat->dead_mutex);
	if (1 == philos->dat->dead)
		i = 1;
	pthread_mutex_unlock(&philo->dat->dead_mutex);
	return(i);
}

int	ft_dead_check(t_philo *philo)//
{

	if (ft_dead_door(philo))
		return (0);
	if (ft_starve(philo))
	{
		pthread_mutex_lock(&philo->dat->dead_mutex);
		philo->dat->dead = 1;
		pthread_mutex_unlock(&philo->dat->dead_mutex);
		printf("%f	-	%d died\n", ft_time_diff(philo->dat->i_time, philo->aux_time), philo->philo_id);
		return (0);
	}
	return (1);
}
