/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:11:51 by uliherre          #+#    #+#             */
/*   Updated: 2023/07/13 16:12:15 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

int	semaphore_create(t_data *dat)
{
	dat->fork_sem = sem_open("/fk", O_CREAT, S_IRUSR | S_IWUSR, dat->p_num / 2);
	if (!dat->fork_sem)
		return (EXIT_FAILURE);
	dat->write_sem = sem_open("/write", O_CREAT, S_IRUSR | S_IWUSR, 1);
	if (!dat->write_sem)
		return (EXIT_FAILURE);
	dat->finish_sem = sem_open("/finish", O_CREAT, S_IRUSR | S_IWUSR, 1);
	if (!dat->finish_sem)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	philos_create(t_data *dat, t_philo *philos)
{
	int	i;

	i = -1;
	philos = (t_philo *)malloc(dat->p_num * sizeof(t_philo));
	if (NULL == philos)
		return ;
	dat->philos = philos;
	dat->i_time = now_time();
	while (++i < dat->p_num)
	{
		philos[i].dat = dat;
		philos[i].philo = fork();
		if (0 > philos[i].philo)
			exit(EXIT_FAILURE);
		else if (philos[i].philo == 0)
			philo_handler((void *)&philos[i]);
		else
		{
			if (i == dat->p_num - 1)
				patrol(philos);
		}
	}
}
