/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:12:52 by uliherre          #+#    #+#             */
/*   Updated: 2023/12/26 12:50:47 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOFERS_H
# define PHILOSOFERS_H
# include <unistd.h>	/*write(), usleep()*/
# include <stdio.h>		/*printf()*/
# include <stdlib.h>	/*malloc()*/
# include <string.h>	/*memset()*/
# include <sys/time.h>	/*gettimeofday()*/
# include <sys/wait.h>	/*waitpid()*/
# include <pthread.h>	/*pthread()*/
# include <signal.h>	/*kill()*/
# include <limits.h>
# include <errno.h>		/*errno*/
# include <semaphore.h>	/*sem_*()*/
# include <fcntl.h>		/*sem O_* constants */
# include <sys/stat.h>	/*sem mode constants */

# define ZERO 0
# define P0 "%ld %s\n"
# define P "%ld %d %s\n"
# define EE "all finish eat.\n"
# define ED "died\n"
# define MSG_0 "has taken a forks"
# define MSG_1 "is eating"
# define MSG_2 "is sleeping"
# define MSG_3 "is thinking"

typedef struct s_data
{
	long	last_eat;
	long	i_time;
	int		philo_id;
	pid_t	*pids;
	int		p_num;
	int		time_to_death;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat;
	sem_t	*forks;
	sem_t	*wall;
}	t_data;

int		core(t_data *dat);	/* proces.c */
void	ft_write_p(t_data *dat, char *msg);	/* actions.c */
void	eat(t_data *dat);					/**/
void	wall(t_data *dat);
void	wait_time(long time_wait);
long	now_time(void);
long	ft_atoi(const char *str);	/* libft.c */
size_t	ft_strlen(char *str);		/**/

#endif
