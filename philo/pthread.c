#include "philosofers.h"

void	*pthread_handler(void *arg)
{
	t_philo		*philo;
	int			i;

	philo = (t_philo *)arg;
	printf("%d - Inicio de las comidas\n", philo->philo_id);/*DEBUG*/
	i = 0;
	while (-1 == philo->dat->must_eat || i++ < philo->dat->must_eat)
	{
		if (eat(philo))//no puede comer si esta muerto
			return ((void *)EXIT_FAILURE);
		if (slepping(philo))//esto lo va a hacer si o si if no ha muerto nadie
			return ((void *)EXIT_FAILURE);
		if (thinking(philo))//aqui no hace nada, simplemente espera por los palillos if no ha muerto nadie
			return ((void *)EXIT_FAILURE);
		i++;
	}
	return ((void *)EXIT_SUCCESS);
}

static int	post_patrol(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->dat->p_num)
		if (pthread_join(philos[i].philo, NULL))
			return (EXIT_FAILURE);
	if (pthread_mutex_unlock(&philos->dat->write_mutex))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	patrol(t_philo *philos)
{
	int	flag;
	int	i;

	flag = 1;
	while (flag)
	{
		i = -1;
		while (++i < philos->dat->p_num)
		{
			if (philos->dat->time_to_death <= time_diff(philos[i].last_eat , now_time()))
			{
				if (pthread_mutex_lock(&philos->dat->write_mutex))
					return (EXIT_FAILURE);
				flag = 0;
				printf("%ld	-	%d %s\n", time_diff(philos->dat->i_time, now_time()), philos[i].philo_id, "is dead\nEND OF SIMULATION");
				break;
			}
		}
	}
	if (post_patrol(philos))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
