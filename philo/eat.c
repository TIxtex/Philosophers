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

static int	take_forks(t_philo *philo, int first, int second)
{
	if (pthread_mutex_lock(&philo->dat->fork_mutex[first]))
		return (errno);
	if (ft_write(philo, "has taken a first fork"))
		return (errno);
	if (pthread_mutex_lock(&philo->dat->fork_mutex[second]))
		return (errno);
	return (ft_write(philo, "has taken a second fork"));
}

static int	leave_forks(t_philo *philo, int first, int second)
{
	if (pthread_mutex_unlock(&philo->dat->fork_mutex[first]))
		return (errno);
	if (ft_write(philo, "has leaven a first fork"))
		return (errno);
	if (pthread_mutex_unlock(&philo->dat->fork_mutex[second]))
		return (errno);
	return (ft_write(philo, "has leaven a second fork"));
}

static int	take_phase(t_philo *philo)
{
	if (philo->philo_id % 2)
	{
		if (philo->philo_id == philo->dat->p_num)
			return (take_forks(philo, philo->philo_id - 1, 0));
		else
			return (take_forks(philo, philo->philo_id, philo->philo_id - 1));
	}
	else
	{
		if (philo->philo_id == philo->dat->p_num)
			return (take_forks(philo, philo->philo_id - 1, 0));
		else
			return (take_forks(philo, philo->philo_id - 1, philo->philo_id));
	}
	return (EXIT_FAILURE);
}

static int	leave_phase(t_philo *philo)
{
	if (philo->philo_id % 2)
	{
		if (philo->philo_id == philo->dat->p_num)
			return (leave_forks(philo, 0, philo->philo_id - 1));
		else
			return (leave_forks(philo, philo->philo_id - 1, philo->philo_id));
	}
	else
	{
		if (philo->philo_id == philo->dat->p_num)
			return (leave_forks(philo, philo->philo_id - 1, 0));
		else
			return (leave_forks(philo, philo->philo_id - 1, philo->philo_id));
	}
	return (EXIT_FAILURE);
}

int	eat(t_philo *philo)
{
	if (take_phase(philo))
		return (errno);
	mv(&philo->last_eat, now_time());
	if (ft_write(philo, "is eating"))
		return (errno);
	if (-1 == wait_time(philo->dat->time_to_eat))
		return (-1);
	return (leave_phase(philo));
}
