#include "../philosofers.h"

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
//		usleep(10);// tiempo de espera para los pares creo que es necesario, veremos en las pruebas finales
		if (philo->philo_id == philo->dat->p_num)
			ft_take_forks(philo, 0, philo->philo_id - 1);
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
			ft_leave_forks(philo, 0, philo->philo_id - 1);
		else
			ft_leave_forks(philo, philo->philo_id - 1, philo->philo_id);
	}
}

void	*ft_eat(t_philo *philo)
{
	ft_take_phase(philo);
	if (ft_dead_check(philo))
		printf("%f	-	%d is eating\n", ft_time_diff(&philo->dat->i_time, &philo->dat->aux_time), philo->philo_id);
	philo->dat->aux_time = ft_wait_time(philo->dat->aux_time, ft_traslate_usec(philo->dat->time_to_eat));
	philo->last_eat = philo->dat->aux_time;
	ft_leave_phase(philo);
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
		ft_eat(philo);//no puede comer si esta muerto
		ft_slepping(philo);//esto lo va a hacer si o si if no ha muerto nadie
		ft_thinking(philo);//aqui no hace nada, simplemente espera por los palillos if no ha muerto nadie
	}

	return (NULL);
}
