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
	int				must_eat;			//Veces que tiene que comer
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	write_mutex;
	long long		i_time;
	t_philo			*philos;
}					t_data;

//FT_MAIN_C
void			ft_patrol(t_philo *philos);
int				ft_starve(t_philo *philo);
//FT_CHECK_ARG_C
int				ft_check_arg(int argc, char **argv);
void			ft_asing_arg(t_data *dat, int argc, char **argv);
//FT_LIBFT_C
long			ft_atoi(const char *str);
//FT_MUTEX_C
int				ft_mutex_create(t_data *dat);
int				ft_thread_create(t_data *dat, t_philo *philos);
//FT_PTHREAD_C
void			*ft_pthread_handler(void *arg);
//FT_ACTIONS_C
void			ft_slepping(t_philo *philo);
void			ft_thinking(t_philo *philo);
void			ft_write(t_philo philo, char *msg);
//FT_EAT_C
void			ft_eat(t_philo *philo);
//FT_TIME_C
long long		ft_time_diff(long long start, long long end);
long long		ft_wait_time(long long time_wait);
long long 		ft_now_time(void);
//FT_DEAD_C
int 			ft_dead_door(t_philo *philo);

#endif