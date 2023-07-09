#include "philosofers.h"

static int	finish_eat(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->dat->finish_mutex))
		return (EXIT_FAILURE);
	philo->dat->finish += 1;
	return (pthread_mutex_unlock(&philo->dat->finish_mutex));
}

void	*pthread_handler(void *arg)
{
	t_philo		*philo;
	int			i;

	philo = (t_philo *)arg;
	printf("%d - Inicio de las comidas\n", philo->philo_id);/*DEBUG*/
	i = 0;
	while (-1 == philo->dat->must_eat || i++ < philo->dat->must_eat)
	{
		if (eat(philo))
			return ((void *)EXIT_FAILURE);
		if (slepping(philo))
			return ((void *)EXIT_FAILURE);
		if (thinking(philo))
			return ((void *)EXIT_FAILURE);
		i++;
	}
	return (finish_eat(philo), NULL);
}

static int	post_patrol(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->dat->p_num)
		if (pthread_join(philos[i].philo, NULL))
			return (EXIT_FAILURE);
	return (pthread_mutex_unlock(&philos->dat->write_mutex));
}

int patrol(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->dat->p_num)
	{
		if (philos->dat->time_to_death <= time_diff(philos[i].last_eat , now_time()))
		{
			if (pthread_mutex_lock(&philos->dat->write_mutex))
				return (EXIT_FAILURE);
			printf("%ld	-	%d %s\n", time_diff(philos->dat->i_time, now_time()), philos[i].philo_id, "is dead\nEND OF SIMULATION");
			break;
		}
		else if (philos->dat->finish == philos->dat->p_num)
		{
			printf("%ld	-	%s\n", time_diff(philos->dat->i_time, now_time()), "all finish eat.\nEND OF SIMULATION");
			break;
		}
		if (i == philos->dat->p_num)
			i = -1;
	}
	return (post_patrol(philos));
}
