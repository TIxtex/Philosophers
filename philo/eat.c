#include "philosofers.h"

static int	take_forks(t_philo *philo, int first, int second)
{
	if (pthread_mutex_lock(&philo->dat->fork_mutex[first]))
		return (EXIT_FAILURE);
	ft_write(philo, "has taken a fork");
	if (pthread_mutex_lock(&philo->dat->fork_mutex[second]))
		return (EXIT_FAILURE);
	ft_write(philo, "has taken a fork");
	return (EXIT_SUCCESS);
}

static int	leave_forks(t_philo *philo, int first, int second)
{
	if (pthread_mutex_unlock(&philo->dat->fork_mutex[first]))
		return (EXIT_FAILURE);
	ft_write(philo, "has leaven a fork");
	if (pthread_mutex_unlock(&philo->dat->fork_mutex[second]))
		return (EXIT_FAILURE);
	ft_write(philo, "has leaven a fork");
	return (EXIT_SUCCESS);
}

static int	take_phase(t_philo *philo)
{
	if (philo->philo_id % 2)/*impares*/
	{
		if (philo->philo_id == philo->dat->p_num)
			take_forks(philo, 0, philo->philo_id - 1);
		else
			take_forks(philo, philo->philo_id, philo->philo_id - 1);
	}
	else
	{
		usleep(philo->dat->time_to_eat / 2);
		if (philo->philo_id == philo->dat->p_num)
			take_forks(philo, philo->philo_id - 1, 0);
		else
			take_forks(philo, philo->philo_id - 1, philo->philo_id);
	}
}

static int	leave_phase(t_philo *philo)
{
	if (philo->philo_id % 2)/*impares*/
	{
		if (philo->philo_id == philo->dat->p_num)
			leave_forks(philo, 0, philo->philo_id - 1);
		else
			leave_forks(philo, philo->philo_id, philo->philo_id - 1);
	}
	else
	{
		if (philo->philo_id == philo->dat->p_num)
			leave_forks(philo, philo->philo_id - 1, 0);
		else
			leave_forks(philo, philo->philo_id - 1, philo->philo_id);
	}
}

int	eat(t_philo *philo)
{
	
	if (take_phase(philo))
		return (EXIT_FAILURE);
	ft_write(philo, "is eating");
	philo->last_eat = wait_time(philo->dat->time_to_eat);//**//
	if (leave_phase(philo))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
