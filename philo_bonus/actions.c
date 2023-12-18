/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:13:20 by uliherre          #+#    #+#             */
/*   Updated: 2023/10/26 19:04:08 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void	wall(t_data *dat)
{
	if (sem_wait(dat->wall))
	{
		free(dat->pids);
		exit (EXIT_FAILURE);
	}
	if (sem_post(dat->wall))
	{
		free(dat->pids);
		exit (EXIT_FAILURE);
	}
}

long	now_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	wait_time(long time_wait)
{
	register long	time_init;

	time_init = now_time();
	while (time_wait > now_time() - time_init)
		usleep(50);
}

void	ft_write_p(t_data *dat, char *msg)
{
	long	aux;

	aux = now_time() - dat->last_eat;
	if (dat->time_to_death > aux)
		printf(P, now_time() - dat->i_time, dat->philo_id, msg);
	else
	{	
		printf(P, now_time() - dat->i_time, dat->philo_id, "dead");
		free(dat->pids);
		exit (42);
	}
}

void	eat(t_data *dat)
{
	if (sem_wait(dat->forks))
	{
		free(dat->pids);
		exit (EXIT_FAILURE);
	}
	ft_write_p(dat, MSG_0);
	ft_write_p(dat, MSG_1);
	dat->last_eat = now_time();
	wait_time(dat->time_to_eat);
	if (sem_post(dat->forks))
	{
		free(dat->pids);
		exit (EXIT_FAILURE);
	}
}
