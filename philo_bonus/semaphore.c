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

void	semaphore_uncreate(sem_t *semaphore, const char *semaphore_name)
{
	sem_close(semaphore);
	sem_unlink(semaphore_name);
	semaphore = NULL;
}

int	semaphore_create(t_data *d, t_philo *philos)
{
	d->forks = sem_open("/forks", O_CREAT, S_IRUSR | S_IWUSR, d->p_num / 2);
	d->write_sem = sem_open("/write", O_CREAT, S_IRUSR | S_IWUSR, 1);
	d->start_sem = sem_open("/start", O_CREAT, S_IRUSR | S_IWUSR, 0);
	d->finish->sem_var = sem_open("/finish", O_CREAT, S_IRUSR | S_IWUSR, 1);
	if (!d->finish->sem_var || !d->start_sem || !d->write_sem || !d->forks)
		return (errno);
	philos = (t_philo *) malloc(d->p_num * sizeof(t_philo));
	if (NULL == philos)
		return (errno);
	d->philos = philos;
	return (EXIT_SUCCESS);
}

int	le_sem_create_and_asign(t_philo *p, int num)
{
	char	*sem_name;
	char	*aux;

	aux = ft_itoa(num);
	if (NULL == aux)
		return (EXIT_FAILURE);
	sem_name = ft_strjoin("le", aux);
	if (NULL == sem_name)
	{
		free (aux);
		return (EXIT_FAILURE);
	}
	p->last_eat->sem_var = sem_open(sem_name, O_CREAT, S_IRUSR | S_IWUSR, 1);
	free (aux);
	free (sem_name);
	if (SEM_FAILED == p->last_eat->sem_var)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	le_sem_destroy(t_philo *p, int num)
{
	char	*sem_name;
	char	*aux;

	aux = ft_itoa(num);
	if (NULL == aux)
		return (EXIT_FAILURE);
	sem_name = ft_strjoin("le", aux);
	if (NULL == sem_name)
	{
		free (aux);
		return (EXIT_FAILURE);
	}
	semaphore_uncreate(p->last_eat->sem_var, sem_name);
	free (aux);
	free (sem_name);
	return (EXIT_SUCCESS);
}

t_philo *philos_create(t_data *dat, t_philo *philos)
{
	int	i;

	i = -1;
	dat->i_time = now_time();
	while (++i < dat->p_num)
	{
		philos[i].dat = dat;
		le_sem_create_and_asign(&philos[i], i);
		philos[i].philo = fork();
		if (0 > philos[i].philo)
			return(NULL);
		else if (philos[i].philo == 0)
		{
			if (philo_handler(&philos[i]) || le_sem_destroy(&philos[i], i))
				return (NULL);
		}
		else if (i == dat->p_num - 1)
		{
			wait_time(dat->time_to_death);
			if (patrol(philos))
				return (NULL);
		}
	}
	return (philos);
}
