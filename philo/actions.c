/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:13:20 by uliherre          #+#    #+#             */
/*   Updated: 2023/10/13 20:19:33 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

int	ft_write(t_philo *philo, char *msg)
{
	long	tmp;

	if (pthread_mutex_lock(&philo->dat->write_mutex))
		return (errno);
	if (av(&philo->dat->finish) >= philo->dat->p_num)
		;
	else
	{
		tmp = time_diff(philo->dat->i_time, now_time());
		printf(P1, tmp, philo->philo_id, msg);
	}
	return (pthread_mutex_unlock(&philo->dat->write_mutex));
}

int	slepping(t_philo *philo)
{
	if (ft_write(philo, "is sleeping"))
		return (errno);
	if (-1 == wait_time(philo->dat->time_to_sleep))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	thinking(t_philo *philo)
{
	return (ft_write(philo, "is thinking"));
}
