/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:12:59 by uliherre          #+#    #+#             */
/*   Updated: 2023/10/13 21:49:07 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

int	mutex_create(t_data *dat)
{
	register int	i;

	dat->fork_mutex = (pthread_mutex_t *) malloc(
			dat->p_num * sizeof(pthread_mutex_t));
	if (NULL == dat->fork_mutex)
		return (errno);
	i = dat->p_num;
	while (i-- > 0)
		if (pthread_mutex_init(&dat->fork_mutex[i], NULL))
			return (errno);
	if (pthread_mutex_init(&dat->write_mutex, NULL))
		return (errno);
	if (pthread_mutex_init(&dat->start_mutex, NULL))
		return (errno);
	if (pthread_mutex_init(&dat->finish.mutex_var, NULL))
		return (errno);
	return (EXIT_SUCCESS);
}

t_philo	*thread_create(t_data *dat, t_philo *philos)
{
	register int	i;

	i = -1;
	philos = (t_philo *) malloc(dat->p_num * sizeof(t_philo));
	if (NULL == philos)
		return (NULL);
	dat->philos = philos;
	if (pthread_mutex_lock(&dat->start_mutex))
		return (NULL);
	while (++i < dat->p_num)
	{
		philos[i].philo_id = i + 1;
		philos[i].dat = dat;
		if (pthread_mutex_init(&philos[i].last_eat.mutex_var, NULL))
			return (NULL);
		if (pthread_create(&philos[i].philo,
				NULL, &pthread_handler, (void *)&philos[i]))
			return (NULL);
	}
	usleep(100);
	dat->i_time = now_time();
	if (pthread_mutex_unlock(&dat->start_mutex))
		return (NULL);
	return (philos);
}
