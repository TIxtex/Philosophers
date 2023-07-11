#include "philosofers.h"

#define ERR_0 "Error al hacer join al hilo o error en el hilo al hacer join"

static int	finish_eat(t_philo *philo)
{
	if (sem_wait(philo->dat->finish_sem))
		return (EXIT_FAILURE);
	philo->dat->finish += 1;
	return (sem_post(philo->dat->finish_sem));
}

void	*philo_handler(void *arg)
{
	t_philo		*philo;
	int			i;

	philo = (t_philo *)arg;
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
/*	int	i;
	void	*aux;

	i = -1;
	aux = NULL;
	while (++i < philos->dat->p_num)
		if (pthread_join(philos[i].philo, aux) || aux)
			return (printf("%s %d\n", ERR_0, i));*/
	return (sem_post(philos->dat->write_sem));
}

int patrol(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->dat->p_num)
	{
		if (philos->dat->time_to_death <= time_diff(philos[i].last_eat , now_time()))
		{
			if (sem_wait(philos->dat->write_sem))
				return (EXIT_FAILURE);
			printf("%ld	-	%d %s\n", time_diff(philos->dat->i_time, now_time()), philos[i].philo, "is dead\nEND OF SIMULATION");
			sleep (1);
			break;
		}
		else if (philos->dat->finish == philos->dat->p_num)
		{
			printf("%ld	-	%s\n", time_diff(philos->dat->i_time, now_time()), "all finish eat.\nEND OF SIMULATION");
			return (post_patrol(philos));
		}
		if (i + 1 == philos->dat->p_num)
			i = -1;
	}
	return (EXIT_SUCCESS);
}
