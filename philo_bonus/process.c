#include "philosofers.h"

#define ERR_K "Error al hacer kill al proceso"

static void	post_patrol(t_data *dat)
{
	register int	i;

	i = ZERO;
	while (i < dat->p_num)
		kill(dat->pids[i++], SIGTERM);
}

static int	patrol(t_data *dat)
{
	pid_t	i;
	int		count;
	int		status;

	count = 0;
	if (sem_post(dat->wall))
		return (post_patrol(dat), EXIT_FAILURE);
	dat->i_time = now_time();
	while (count != dat->p_num)
	{
		i = waitpid(-1, &status, 0);
		if (0 > i || EXIT_FAILURE == WEXITSTATUS(status))
			return (EXIT_FAILURE);
		if (EXIT_SUCCESS == WEXITSTATUS(status))
			count++;
		else if (42 == WEXITSTATUS(status))
			return (post_patrol(dat), 42);
	}
	return (printf(P0, now_time() - dat->i_time, EE), EXIT_SUCCESS);
}

static int	philo_handler(t_data *dat)
{
	int			i;

	i = 0;
	wall(dat);
	dat->i_time = now_time();
	dat->last_eat = dat->i_time;
	while (-1 == dat->must_eat || i++ < dat->must_eat)
	{
		eat(dat);
		ft_write_p(dat, MSG_2);
		wait_time(dat->time_to_sleep);
		ft_write_p(dat, MSG_3);
		wait_time(2);
	}
	return (free(dat->pids), EXIT_SUCCESS);
}

int	core(t_data *dat)
{
	int	i;

	i = -1;
	while (++i < dat->p_num)
	{
		dat->pids[i] = fork();
		if (0 > dat->pids[i])
			return(EXIT_FAILURE);
		else if (dat->pids[i] == 0)
		{
			dat->philo_id = i;
			exit (philo_handler(dat));
		}
		if (i == dat->p_num - 1)
			return (patrol(dat));
	}
	return (EXIT_SUCCESS);
}
