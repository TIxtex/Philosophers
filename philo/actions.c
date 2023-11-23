/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:13:20 by uliherre          #+#    #+#             */
/*   Updated: 2023/10/21 16:14:17 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void	ft_write(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->dat->finish.mutex_var);
	if (philo->dat->finish.var < philo->dat->p_num)
		printf(P, now_time() - philo->dat->i_time, philo->philo_id, msg);
	pthread_mutex_unlock(&philo->dat->finish.mutex_var);
}

void	slepping(t_philo *philo)
{
	ft_write(philo, MSG_2);
	wait_time(philo->dat->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	ft_write(philo, MSG_3);
	wait_time(1);
}
