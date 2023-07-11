#include "philosofers.h"

int	semaphore_create(t_data *dat)
{
	int	i;

	dat->fork_sem = sem_open("fork", O_CREAT);
	if (!dat->fork_sem)
		return (EXIT_FAILURE);
	i = -1;
	while (dat->p_num / 2 > ++i)
		if (sem_post(dat->fork_sem))
			return (EXIT_FAILURE);
	dat->write_sem = sem_open("write", O_CREAT);
	if (!dat->write_sem)
		return (EXIT_FAILURE);
	dat->finish_sem = sem_open("finish", O_CREAT);
	if (!dat->finish_sem)
		return (EXIT_FAILURE);
	if (sem_post(dat->finish_sem))
		return (EXIT_FAILURE);
	return (sem_post(dat->write_sem));
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
