#include "philosofers.h"

void	*ft_take_forks(t_philo *philo, int first, int second)
{
	if (pthread_mutex_lock(&philo->dat->fork_mutex[first]))
		return (NULL);
	if (ft_dead_door(philo))
		ft_write(philo, "has taken a fork"):
	if (pthread_mutex_lock(&philo->dat->fork_mutex[second]))
		return (NULL);
	if (ft_dead_door(philo))
		ft_write(philo, "has taken a fork");
	return (NULL);
}

void	*ft_leave_forks(t_philo *philo, int first, int second)
{
	if (pthread_mutex_unlock(&philo->dat->fork_mutex[first]))
		return (NULL);
	if (ft_dead_door(philo))
		ft_write(philo, "has leaven a fork");
	if (pthread_mutex_unlock(&philo->dat->fork_mutex[second]))
		return (NULL);
	if (ft_dead_door(philo))
		ft_write(philo, "has leaven a fork");
	return (NULL);
}

void	ft_take_phase(t_philo *philo)
{
	if (philo->philo_id % 2)//impar
	{
		if (philo->philo_id == philo->dat->p_num)
			ft_take_forks(philo, 0, philo->philo_id - 1);
		else
			ft_take_forks(philo, philo->philo_id, philo->philo_id - 1);
	}
	else
	{
		usleep(10);// tiempo de espera para los pares creo que es necesario, veremos en las pruebas finales
		if (philo->philo_id == philo->dat->p_num)
			ft_take_forks(philo, philo->philo_id - 1, 0);
		else
			ft_take_forks(philo, philo->philo_id - 1, philo->philo_id);
	}
}

void	ft_leave_phase(t_philo *philo)
{
	if (philo->philo_id % 2)//impar
	{
		if (philo->philo_id == philo->dat->p_num)
			ft_leave_forks(philo, 0, philo->philo_id - 1);
		else
			ft_leave_forks(philo, philo->philo_id, philo->philo_id - 1);
	}
	else
	{
		if (philo->philo_id == philo->dat->p_num)
			ft_leave_forks(philo, philo->philo_id - 1, 0);
		else
			ft_leave_forks(philo, philo->philo_id - 1, philo->philo_id);
	}
}

void	ft_eat(t_philo *philo)
{
	ft_take_phase(philo);
	if (ft_dead_door(philo))
		ft_write(philo, "is eating");
	philo->last_eat = ft_wait_time(philo->dat->time_to_eat);//**//
	ft_leave_phase(philo);
}
