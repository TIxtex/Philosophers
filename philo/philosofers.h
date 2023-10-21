/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:12:52 by uliherre          #+#    #+#             */
/*   Updated: 2023/10/13 23:12:58 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOFERS_H
# define PHILOSOFERS_H
# include <unistd.h>	/*write(), usleep()*/
# include <stdio.h>		/*printf()*/
# include <stdlib.h>	/*malloc()*/
# include <string.h>	/*memset()*/
# include <sys/time.h>	/*gettimeofday()*/
# include <pthread.h>	/*pthread()*/
# include <limits.h>
# include <errno.h>		/*errno*/

# define ZERO 0
# define ERR_0 "Error al hacer join al hilo o error en el hilo al hacer join"
# define ERR_A "Error ARGS\n"
# define P0 "%ld %s\n"
# define P1 "%ld %d %s\n"
# define EE "all finish eat.\n"
# define ED "died\n"
# define MSG_0 "has taken a fork"
# define MSG_1 "is eating"
# define MSG_2 "is sleeping"
# define MSG_3 "is thinking"

struct	s_data;

typedef struct s_share
{
	pthread_mutex_t	mutex_var;
	long			var;
}	t_share;

typedef struct s_philo
{
	t_share			last_eat;
	int				philo_id;
	struct s_data	*dat;
	pthread_t		philo;
}	t_philo;

typedef struct s_data
{
	t_share			finish;
	int				p_num;
	int				time_to_death;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	start_mutex;
	long			i_time;
	t_philo			*philos;
}	t_data;

long		ft_atoi(const char *str);
size_t		ft_strlen(char *str);
int			mutex_create(t_data *dat);
t_philo		*thread_create(t_data *dat, t_philo *philos);
void		*pthread_handler(void *arg);
int			patrol(t_philo *philos);
void		slepping(t_philo *philo);
void		thinking(t_philo *philo);
void		ft_write(t_philo *philo, char *msg);
void		eat(t_philo *philo);
void		wait_time(long time_wait);
long		now_time(void);
long		av(t_share *v);
void		mv(t_share *v, long value);

#endif
