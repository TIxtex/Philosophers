#ifndef PHILOSOFERS_H
# define PHILOSOFERS_H
# include <unistd.h>	//write(), usleep(),
# include <stdio.h>		//printf()
# include <stdlib.h>	//malloc()
# include <string.h>	//memset()
# include <sys/time.h>	//gettimeofday()
# include <pthread.h>	//pthread()

struct s_data;

typedef struct s_philo
{
	pthread_t		philo;
	int				philo_id;
	long long		last_eat;
	struct s_data	*dat;
}					t_philo;

typedef struct s_data
{
	int				dead;
	int				p_num;
	int				time_to_death;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	write_mutex;
	long long		i_time;
	t_philo			*philos;
}					t_data;

void			patrol(t_philo *philos);
int				starve(t_philo *philo);
int				check_arg(int argc, char **argv);
void			asing_arg(t_data *dat, int argc, char **argv);
long			ft_atoi(const char *str);
int				mutex_create(t_data *dat);
t_philo			*thread_create(t_data *dat, t_philo *philos);
void			*pthread_handler(void *arg);
void			slepping(t_philo *philo);
void			thinking(t_philo *philo);
void			ft_write(t_philo *philo, char *msg);
void			eat(t_philo *philo);
long long		time_diff(long long start, long long end);
long long		wait_time(long long time_wait);
long long 		now_time(void);
int 			dead_door(t_philo *philo);

#endif