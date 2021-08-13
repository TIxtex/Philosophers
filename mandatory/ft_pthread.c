#include "../philosofers.h"

void	ft_wait_time(t_philo *philo, int time_wait)
{
	struct timeval	time_now;
	gettimeofday(&time_now, NULL);
	gettimeofday(philo->dat->aux_time, NULL);
	philo->dat->aux_time.tv_usec =+ time_wait - 1;//
	while (philo->dat->aux_time.tv_usec > time_now.tv_usec)
		gettimeofday(&time_now, NULL);
}

void	*ft_take_forks(t_philo *philo, int first, int second)
{
	if (pthread_mutex_lock(&philo->dat->mutex[first]))
		return (NULL);
	printf("%d	-	%d has taken a fork\n", philo->dat->i_time, philo->philo_id);
	if (pthread_mutex_lock(&philo->dat->mutex[second]))
		return (NULL);
	printf("%d has taken a fork\n", philo->philo_id);
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

void	*ft_eat(t_philo *philo)
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
		usleep(10);
		if (philo->philo_id == philo->dat->p_num)
			ft_take_forks(philo, 0, philo->philo_id - 1);
		else
			ft_take_forks(philo, philo->philo_id - 1, philo->philo_id);
	}
	printf("%d is eating\n", philo->philo_id);
	ft_wait_time(philo, philo->dat->time_to_eat);
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
			ft_leave_forks(philo, 0, philo->philo_id - 1);
		else
			ft_leave_forks(philo, philo->philo_id - 1, philo->philo_id);
	}
	return (NULL);
}

void	ft_slepping(t_philo *philo)
{
	printf("%d is sleeping\n", philo->philo_id);
	ft_wait_time(philo, philo->dat->time_to_sleep);
}

void	ft_thinking(t_philo *philo)
{
	printf("%d is thinking\n", philo->philo_id);
	ft_wait_time(philo, philo->dat->time_to_death);
}

void	ft_dead(t_philo *philo)
{
	printf("%d died\n", philo->philo_id);
//	pthread_detach(dat->philos[dat->philos->philo_id - 1].philo);
}

void	*ft_pthread_handler(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		ft_eat(philo);
		ft_slepping(philo);
		ft_thinking(philo);
	}
	ft_dead(philo);
	return (NULL);
}
