#include "philosofers.h"

static int	take_forks(t_philo *philo, int first, int second)
{
	if (pthread_mutex_lock(&philo->dat->fork_mutex[first]))
		return (EXIT_FAILURE);
	if (ft_write(philo, "has taken a 1 fork"))
		return (EXIT_FAILURE);
	if (pthread_mutex_lock(&philo->dat->fork_mutex[second]))
		return (EXIT_FAILURE);
	return (ft_write(philo, "has taken a 2 fork"));
}

static int	leave_forks(t_philo *philo, int first, int second)
{
	if (pthread_mutex_unlock(&philo->dat->fork_mutex[first]))
		return (EXIT_FAILURE);
	if (ft_write(philo, "has leaven a 1 fork"))
		return (EXIT_FAILURE);
	if (pthread_mutex_unlock(&philo->dat->fork_mutex[second]))
		return (EXIT_FAILURE);
	return (ft_write(philo, "has leaven a 2 fork"));
}

static int	take_phase(t_philo *philo)
{
	if (philo->philo_id % 2)/*impares*/
	{
		if (philo->philo_id == philo->dat->p_num)
		{
			if (take_forks(philo, 0, philo->philo_id - 1))
				return (EXIT_FAILURE);
		}
		else if (take_forks(philo, philo->philo_id, philo->philo_id - 1))
			return (EXIT_FAILURE);
	}
	else
	{
		usleep(philo->dat->time_to_eat / 4);
		if (philo->philo_id == philo->dat->p_num)
		{
			if (take_forks(philo, philo->philo_id - 1, 0))
				return (EXIT_FAILURE);
		}
		else if (take_forks(philo, philo->philo_id - 1, philo->philo_id))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	leave_phase(t_philo *philo)
{
	if (philo->philo_id % 2)/*impares*/
	{
		if (philo->philo_id == philo->dat->p_num)
		{
			if(leave_forks(philo, 0, philo->philo_id - 1))
				return (EXIT_FAILURE);
		}
		else if(leave_forks(philo, philo->philo_id, philo->philo_id - 1))
			return (EXIT_FAILURE);
	}
	else
	{
		if (philo->philo_id == philo->dat->p_num)
		{
			if (leave_forks(philo, philo->philo_id - 1, 0))
				return (EXIT_FAILURE);
		}
		else if (leave_forks(philo, philo->philo_id - 1, philo->philo_id))
				return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	eat(t_philo *philo)
{
	
	if (take_phase(philo))
		return (EXIT_FAILURE);
	if (ft_write(philo, "is eating"))
		return (EXIT_FAILURE);
	philo->last_eat = wait_time(philo->dat->time_to_eat);//**//
	return (leave_phase(philo));
}
