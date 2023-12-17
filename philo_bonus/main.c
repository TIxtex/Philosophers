/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:39:31 by uliherre          #+#    #+#             */
/*   Updated: 2023/10/26 19:02:56 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"
#define ERR_A "Error ARGS\n"
#define ERR_PNUM "Need more than ONE philosofer\n"

static void	free_all(t_data *dat, t_philo *philos)/*MOD*/
{
	wait_time(100);
	semaphore_uncreate(dat->forks, "/forks");
	semaphore_uncreate(dat->write_sem, "/write");
	semaphore_uncreate(dat->start_sem, "/start");
	semaphore_uncreate(dat->finish->sem_var, "/finish");
	if (NULL != philos)
	{
		free(philos);
		philos = NULL;
	}
}

static void	asing_arg(t_data *dat, int argc, char **argv)
{
	dat->p_num = (int)ft_atoi(argv[1]);
	if (2 > dat->p_num)
		ft_error(ERR_PNUM, 83);
	dat->time_to_death = (int)ft_atoi(argv[2]);
	dat->time_to_eat = (int)ft_atoi(argv[3]);
	dat->time_to_sleep = (int)ft_atoi(argv[4]);
	if (6 == argc)
		dat->must_eat = (int)ft_atoi(argv[5]);
	else
		dat->must_eat = -1;
	dat->forks = NULL;
	dat->write_sem = NULL;
	dat->start_sem = NULL;
}

static int	check_argv(char *argv)
{
	register size_t	i;

	i = ft_strlen(argv);
	if (10 < i || 0 == i || '0' == argv[0])
		return (EXIT_FAILURE);
	i = ZERO;
	while (argv[i])
	{
		if (!((unsigned)argv[i] - '0' < 10))
			return (EXIT_FAILURE);
		i++;
	}
	i = ft_atoi(argv);
	return (INT_MAX < i);
}

static int	check_arg(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		;
	else if (check_argv(argv[1])
		|| check_argv(argv[2])
		|| check_argv(argv[3])
		|| check_argv(argv[4]))
		;
	else if (6 == argc && check_argv(argv[5]))
		;
	else
		return (EXIT_SUCCESS);
	return (write(STDERR_FILENO, ERR_A, 11));
}

int	main(int argc, char **argv)/*MOD*/
{
	t_data	dat;
	t_philo	*philos;

	philos = NULL;
	if (check_arg(argc, argv))
		return (EXIT_FAILURE);
	if (asing_arg(&dat, argc, argv), semaphore_create(&dat, philos))
		return (errno);
	philos = philos_create(&dat, philos);
	wait_time(dat.time_to_death);
	if (NULL == philos)
		return (free_all(&dat, NULL), EXIT_FAILURE);
	return (free_all(&dat, philos), EXIT_SUCCESS);
}
