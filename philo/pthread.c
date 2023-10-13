/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:11:51 by uliherre          #+#    #+#             */
/*   Updated: 2023/10/13 23:45:56 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

static int	wall(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->dat->start_mutex))
		return (errno);
	mv(&philo->last_eat, now_time());
	if (pthread_mutex_unlock(&philo->dat->start_mutex))
		return (errno);
	return (EXIT_SUCCESS);
}

static int	finish_eat(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->dat->finish.mutex_var))
		return (errno);
	philo->dat->finish.var += 1;
	if (pthread_mutex_unlock(&philo->dat->finish.mutex_var))
		return (errno);
	mv(&philo->last_eat, LONG_MAX);
	return (EXIT_SUCCESS);
}

void	*pthread_handler(void *arg)
{
	t_philo			*philo;
	register int	i;

	philo = (t_philo *)arg;
	i = 0;
	if (wall(philo))
		return (NULL);
	if (!(philo->philo_id % 2))
		usleep(100);
	while (-1 == philo->dat->must_eat || i++ < philo->dat->must_eat)
	{
		if (eat(philo))
			return ((void *)EXIT_FAILURE);
		if (slepping(philo))
			return ((void *)EXIT_FAILURE);
		if (thinking(philo))
			return ((void *)EXIT_FAILURE);
		if (av(&philo->dat->finish) >= philo->dat->p_num)
			break ;
	}
	return (finish_eat(philo), NULL);
}

static int	post_patrol(t_philo *philos)
{
	register int	i;

	i = -1;
	while (++i < philos->dat->p_num)
		if (pthread_join(philos[i].philo, NULL))
			return (printf("%s %d\n", ERR_0, i), errno);
	return (EXIT_SUCCESS);
}

int	patrol(t_philo *philos)
{
	register int	i;
	long			tmp;

	i = -1;
	sleep(1);
	while (++i < philos->dat->p_num)
	{
		tmp = time_diff(av(&philos[i].last_eat), now_time());
		if (av(&philos->dat->finish) >= philos->dat->p_num)
		{
			printf(P0, time_diff(philos->dat->i_time, now_time()), EE);
			break ;
		}
		else if (philos->dat->time_to_death <= tmp && tmp < 100000)
		{
			mv(&philos->dat->finish, philos->dat->p_num);
			usleep(100);
			printf(P1, time_diff(philos->dat->i_time, now_time()),
				philos[i].philo_id, ED);
			break ;
		}
		if (i + 1 == philos->dat->p_num)
			i = -1;
	}
	return (post_patrol(philos));
}
