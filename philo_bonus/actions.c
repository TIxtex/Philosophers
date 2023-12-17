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

void	ft_write_p(t_philo *philo, char *msg)
{
	if (sem_wait(philo->dat->write_sem))
		exit (-12);
	if (av(philo->dat->finish) < philo->dat->p_num)
		printf(P, now_time() - philo->dat->i_time, philo->philo_id, msg);
	if (sem_post(philo->dat->write_sem))
		exit (-12);
}

void	eat(t_philo *philo)
{
	if (sem_wait(philo->dat->forks))
		exit (-13);
	ft_write_p(philo, MSG_0);
	ft_write_p(philo, MSG_1);
	mv(philo->last_eat, now_time());
	wait_time(philo->dat->time_to_eat);
	if (sem_post(philo->dat->forks))
		exit (-13);
}

void	slepping(t_philo *philo)
{
	ft_write_p(philo, MSG_2);
	wait_time(philo->dat->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	ft_write_p(philo, MSG_3);
	wait_time(1);
}
