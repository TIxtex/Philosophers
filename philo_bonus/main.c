/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:39:31 by uliherre          #+#    #+#             */
/*   Updated: 2023/12/26 12:50:25 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

#define FORK_SEM "/forks"
#define WALL_SEM "/wall"
#define ERR_A "Error ARGS\n"
#define ERR_PNUM "Need more than ONE philosofer\n"

static int	asing_arg(t_data *dat, int argc, char **argv)
{
	dat->p_num = (int)ft_atoi(argv[1]);
	if (2 > dat->p_num || 200 < dat->p_num)
		return (EXIT_FAILURE);
	dat->time_to_death = (int)ft_atoi(argv[2]);
	dat->time_to_eat = (int)ft_atoi(argv[3]);
	dat->time_to_sleep = (int)ft_atoi(argv[4]);
	if (6 == argc)
		dat->must_eat = (int)ft_atoi(argv[5]);
	else
		dat->must_eat = -1;
	dat->forks = NULL;
	dat->wall = NULL;
	dat->pids = NULL;
	return (EXIT_SUCCESS);
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
	return (write(STDERR_FILENO, ERR_A, sizeof(ERR_A)));
}

static void	ft_idempotence(t_data *dat)
{
	sem_close(dat->forks);
	sem_unlink(FORK_SEM);
	sem_close(dat->wall);
	sem_unlink(WALL_SEM);
}

int	main(int argc, char **argv)
{
	t_data	dat;
	int		result;

	if (check_arg(argc, argv))
		return (EXIT_FAILURE);
	if (asing_arg(&dat, argc, argv))
		return (EXIT_FAILURE);
	dat.pids = (pid_t *) malloc(dat.p_num * sizeof(pid_t));
	if (NULL == dat.pids)
		return (EXIT_FAILURE);
	ft_idempotence(&dat);
	dat.forks = sem_open(FORK_SEM, O_CREAT | O_EXCL, 0666, dat.p_num / 2);
	dat.wall = sem_open(WALL_SEM, O_CREAT | O_EXCL, 0666, 0);
	if (SEM_FAILED == dat.forks)
		return (free(dat.pids), errno);
	result = core(&dat);
	wait_time(dat.time_to_death);
	free(dat.pids);
	ft_idempotence(&dat);
	return (result);
}
