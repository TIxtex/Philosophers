/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:12:52 by uliherre          #+#    #+#             */
/*   Updated: 2023/10/26 19:40:45 by uliherre         ###   ########.fr       */
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
# include <signal.h>
# include <limits.h>
# include <errno.h>		/*errno*/
# include <semaphore.h>
# include <fcntl.h>		/* For O_* constants */
# include <sys/stat.h>	/* For mode constants */
# define ZERO 0
# define P0 "%ld %s\n"
# define P "%ld %d %s\n"
# define EE "all finish eat.\n"
# define ED "died\n"
# define MSG_0 "has taken a forks"
# define MSG_1 "is eating"
# define MSG_2 "is sleeping"
# define MSG_3 "is thinking"

struct	s_data;

typedef struct s_share
{
	sem_t			*sem_var;
	long			var;
}	t_share;

typedef struct s_philo
{
	t_share			*last_eat;
	int				philo_id;
	pid_t			philo;
	struct s_data	*dat;
}	t_philo;

typedef struct s_data
{
	t_share			*finish;
	int				p_num;
	int				time_to_death;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	sem_t			*forks;
	sem_t			*write_sem;
	sem_t			*start_sem;
	long			i_time;
	t_philo			*philos;
}	t_data;

void		ft_error(const char *errstr, int errnum);
long		ft_atoi(const char *str);
char		*ft_itoa(long n);
size_t		ft_strlen(char *str);
char		*ft_strjoin(char const *s1, char const *s2);
int			semaphore_create(t_data *d, t_philo *philos);
void		semaphore_uncreate(sem_t *semaphore, const char *semaphore_name);
t_philo 	*philos_create(t_data *dat, t_philo *philos);
void		*philo_handler(t_philo *philo);
int			patrol(t_philo *philos);
void		slepping(t_philo *philo);
void		thinking(t_philo *philo);
void		ft_write_p(t_philo *philo, char *msg);
void		eat(t_philo *philo);
void		wait_time(long time_wait);
long		now_time(void);

/** Wrapers **/
long		av(t_share *v);
void		mv(t_share *v, long value);

#endif
