/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:13:12 by uliherre          #+#    #+#             */
/*   Updated: 2023/10/13 23:44:33 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

static void	take_forks(t_philo *philo, int first, int second)
{
	pthread_mutex_lock(&philo->dat->fork_mutex[first]);
	ft_write(philo, MSG_0);
	pthread_mutex_lock(&philo->dat->fork_mutex[second]);
	ft_write(philo, MSG_0);
}

static void	leave_forks(t_philo *philo, int first, int second)
{
	pthread_mutex_unlock(&philo->dat->fork_mutex[first]);
	pthread_mutex_unlock(&philo->dat->fork_mutex[second]);
}

static void	take_phase(t_philo *philo)
{
	if (philo->philo_id % 2)
	{
		if (philo->philo_id == philo->dat->p_num)
			take_forks(philo, ZERO, philo->philo_id - 1);
		else
			take_forks(philo, philo->philo_id, philo->philo_id - 1);
	}
	else
	{
		if (philo->philo_id == philo->dat->p_num)
			take_forks(philo, philo->philo_id - 1, ZERO);
		else
			take_forks(philo, philo->philo_id - 1, philo->philo_id);
	}
}

static void	leave_phase(t_philo *philo)
{
	if (philo->philo_id % 2)
	{
		if (philo->philo_id == philo->dat->p_num)
			leave_forks(philo, philo->philo_id - 1, ZERO);
		else
			leave_forks(philo, philo->philo_id, philo->philo_id - 1);
	}
	else
	{
		if (philo->philo_id == philo->dat->p_num)
			leave_forks(philo, philo->philo_id - 1, ZERO);
		else
			leave_forks(philo, philo->philo_id - 1, philo->philo_id);
	}
}

void	eat(t_philo *philo)
{
	take_phase(philo);
	mv(&philo->last_eat, now_time());
	ft_write(philo, MSG_1);
	wait_time(philo->dat->time_to_eat);
	leave_phase(philo);
}
