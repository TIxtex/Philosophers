#include "../philosofers.h"

int		ft_jamelgo(t_philo *philo)
{
	
}

void	ft_dead_check(t_philo *philo)
{
	if (philo->dat->dead)
		pthread_detach(philo->philo[philo->philo_id]);
	/*ver si se ha quedado jamelgo*/
	printf("%f	-	%d died\n", ft_time_diff(&philo->dat->i_time, &philo->dat->aux_time), philo->philo_id);
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
//		philo->dat->aux_time = ft_wait_time(philo->dat->aux_time, ft_traslate_usec(200));// tiempo de espera para los pares creo que es necesario, veremos en las pruebas finales
		if (philo->philo_id == philo->dat->p_num)
			ft_take_forks(philo, 0, philo->philo_id - 1);
		else
			ft_take_forks(philo, philo->philo_id - 1, philo->philo_id);
	}
	printf("%f	-	%d is eating\n", ft_time_diff(&philo->dat->i_time, &philo->dat->aux_time), philo->philo_id);
	philo->dat->aux_time = ft_wait_time(philo->dat->aux_time, ft_traslate_usec(philo->dat->time_to_eat));
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

void	*ft_pthread_handler(void *arg)
{
	t_philo		*philo;
	int			i;

	philo = (t_philo *)arg;
	i = 0;
	while (-1 == philo->dat->must_eat || i++ < philo->dat->must_eat)
	{
		ft_eat(philo);
		ft_slepping(philo);
		ft_thinking(philo);
	}
	return (NULL);
}
