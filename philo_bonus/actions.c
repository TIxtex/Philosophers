#include "philosofers.h"

int	ft_write(t_philo *philo, char *msg)
{
	if (sem_wait(philo->dat->write_sem))
		return (errno);
	if (philo->dat->finish == philo->dat->p_num)
	{
		if (sem_post(philo->dat->write_sem))
			return(errno);
		exit (EXIT_SUCCESS);
	}
	else
		printf("%ld	-	%d %s\n", time_diff(philo->dat->i_time, now_time()), philo->philo, msg);
	return (sem_post(philo->dat->write_sem));
}

int	eat(t_philo *philo)
{
	
	if (sem_wait(philo->dat->fork_sem))
		return (errno);
	if (ft_write(philo, "is eating"))
		return (EXIT_FAILURE);
	philo->last_eat = wait_time(philo->dat->time_to_eat);
	return (sem_post(philo->dat->fork_sem));
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
	return (ft_write(philo, "is thinking"));
}
