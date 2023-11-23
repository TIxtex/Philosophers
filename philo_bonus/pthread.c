/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:11:51 by uliherre          #+#    #+#             */
/*   Updated: 2023/10/26 19:03:16 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"
#define UPS "Soy solo un filosofo, no tengo otro tenedor"

static void	wall(t_philo *philo)/*MOD*/
{
	pthread_mutex_lock(&philo->dat->start_mutex);
	mv(&philo->last_eat, now_time());
	pthread_mutex_unlock(&philo->dat->start_mutex);
}

static int	finish_eat(t_philo *philo)/*MOD*/
{
	pthread_mutex_lock(&philo->dat->finish.mutex_var);
	philo->dat->finish.var += 1;
	pthread_mutex_unlock(&philo->dat->finish.mutex_var);
	mv(&philo->last_eat, LONG_MAX);
	return (EXIT_SUCCESS);
}

void	*pthread_handler(void *arg)/*MOD*/
{
	t_philo			*philo;
	register int	i;

	philo = (t_philo *)arg;
	if (1 == philo->dat->p_num)
		return (ft_write(philo, UPS), NULL);
	i = 0;
	wall(philo);
	if (!(philo->philo_id % 2))
		wait_time(2);
	while (-1 == philo->dat->must_eat || i++ < philo->dat->must_eat)
	{
		eat(philo);
		slepping(philo);
		thinking(philo);
		if (av(&philo->dat->finish) >= philo->dat->p_num)
			break ;
	}
	return (finish_eat(philo), NULL);
}

static int	post_patrol(t_philo *philos)/*MOD*/
{
	register int	i;

	i = -1;
	while (++i < philos->dat->p_num)
		if (pthread_join(philos[i].philo, NULL))
			return (printf("%s %d\n", ERR_0, i), errno);
	return (EXIT_SUCCESS);
}

int	patrol(t_philo *philos)/*MOD*/
{
	register int	i;
	long			tmp;

	i = -1;
	while (++i < philos->dat->p_num && 1 != philos->dat->p_num)
	{
		tmp = now_time() - av(&philos[i].last_eat);
		if (av(&philos->dat->finish) >= philos->dat->p_num)
		{
			printf(P0, now_time() - philos->dat->i_time, EE);
			break ;
		}
		else if (philos->dat->time_to_death <= tmp && tmp < 100000)
		{
			mv(&philos->dat->finish, philos->dat->p_num);
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
