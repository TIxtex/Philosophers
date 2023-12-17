#include "philosofers.h"

#define ERR_K "Error al hacer kill al proceso"

static void	wall(t_philo *philo)/*MOD*/
{
	sem_wait(philo->dat->start_sem);
	sem_post(philo->dat->start_sem);
}

static int	finish_eat(t_philo *philo)
{
	if (sem_wait(philo->dat->finish->sem_var))
		return (EXIT_FAILURE);
	philo->dat->finish->var += 1;
	return (sem_post(philo->dat->finish->sem_var));
}

void	*philo_handler(t_philo *philo)
{
	int			i;

	i = 0;
	wall(philo);
	while (-1 == philo->dat->must_eat || i++ < philo->dat->must_eat)
	{
		eat(philo);
		slepping(philo);
		thinking(philo);
		i++;
	}
	return (finish_eat(philo), NULL);
}

static int	post_patrol(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->dat->p_num)
		if (kill(philos[i].philo, SIGTERM))
			return (printf("%s %d\n", ERR_K, i));
	return (sem_post(philos->dat->write_sem));
}

int	patrol(t_philo *philos)
{
	register int	i;
	long			tmp;

	i = -1;
	while (++i < philos->dat->p_num && 1 != philos->dat->p_num)
	{
		tmp = now_time() - av(philos[i].last_eat);
		if (av(philos->dat->finish) >= philos->dat->p_num)
		{
			printf(P0, now_time() - philos->dat->i_time, EE);
			break ;
		}
		else if (philos->dat->time_to_death <= tmp && tmp < 100000)
		{
			mv(philos->dat->finish, philos->dat->p_num);
			wait_time(1);
			printf(P, now_time() - philos->dat->i_time, philos[i].philo_id, ED);
			break ;
		}
		wait_time(1);
		if (i + 1 == philos->dat->p_num)
			i = -1;
	}
	return (post_patrol(philos));
}
