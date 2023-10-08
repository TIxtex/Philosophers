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

#define ZERO 0

struct s_data;

typedef struct s_share
{
	pthread_mutex_t	mutex_var;
	long			var;
}	t_share;

typedef struct s_philo
{
	pthread_t		philo;
	int				philo_id;
	t_share			last_eat;
	struct s_data	*dat;
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
	long			i_time;
	t_philo			*philos;
}	t_data;

long		ft_atoi(const char *str);
size_t		ft_strlen(char *str);
int			mutex_create(t_data *dat);
t_philo		*thread_create(t_data *dat, t_philo *philos);
void		*pthread_handler(void *arg);
int			patrol(t_philo *philos);
int			slepping(t_philo *philo);
int			thinking(t_philo *philo);
int			ft_write(t_philo *philo, char *msg);
int			eat(t_philo *philo);
long		time_diff(long start, long end);
long		wait_time(long time_wait);
long 		now_time(void);
long		av(t_share v);
void		mv(t_share *v, long value);

#endif
