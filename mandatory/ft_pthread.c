#include "../philosofers.h"

int		ft_starve_together(t_philo *philo)
{
	if (ft_traslate_usec(philo->dat->time_to_death) < ft_time_diff(&philo->last_eat, &philo->dat->aux_time))
		return (1);
	return (0);
}

void	ft_dead_check(t_philo *philo)
{
	philo->dat->aux_time = ft_wait_time(philo->dat->aux_time, 0);//refress aux_time
//	printf("-->Debug deadcheck philo:%d time to init:%f\n", philo->philo_id, ft_time_diff(&philo->last_eat, &philo->dat->aux_time));
	if (philo->dat->dead)
	{
//		pthread_detach(philo->philo);
		pthread_join(philo->philo, NULL);
		printf("Detach el hilo %d con la dirección:%p	\n", philo->philo_id - 1, (void *)&philo->philo);
	}
	if (ft_starve_together(philo))
	{
		philo->dat->dead = 1;
		printf("%f	-	%d died\n", ft_time_diff(&philo->dat->i_time, &philo->dat->aux_time), philo->philo_id);
//		pthread_detach(philo->philo);
		pthread_join(philo->philo, NULL);
		printf("Detach el hilo %d con la dirección:%p	\n", philo->philo_id - 1, (void *)&philo->philo);
	}
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
	ft_dead_check(philo);
	printf("%f	-	%d is eating\n", ft_time_diff(&philo->dat->i_time, &philo->dat->aux_time), philo->philo_id);
	philo->dat->aux_time = ft_wait_time(philo->dat->aux_time, ft_traslate_usec(philo->dat->time_to_eat));
	philo->last_eat = philo->dat->aux_time;
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
		ft_eat(philo);//no puede comer si esta muerto
		ft_slepping(philo);//esto lo va a hacer si o si if no ha muerto nadie
		ft_thinking(philo);//aqui no hace nada, simplemente espera por los palillos if no ha muerto nadie
	}
	return (NULL);
}
