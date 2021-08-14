#ifndef PHILOSOFERS_H
# define PHILOSOFERS_H
# include <unistd.h>//write(), usleep(),
# include <stdio.h>//printf()
# include <stdlib.h>//malloc()
# include <string.h>//memset()
# include <sys/time.h>//gettimeofday
# include <pthread.h>//pthread

typedef struct s_data
{
	int				p_num;
	int				time_to_death;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	pthread_mutex_t	*mutex;
	struct timeval	i_time;
	struct timeval	aux_time;
}					t_data;

typedef struct s_philo
{
	pthread_t		philo;
	int				philo_id;
	t_data			*dat;
}					t_philo;

//FT_CHECK_ARG_C
int			ft_check_arg(int argc, char **argv);
void		ft_asing_arg(t_data *dat, int argc, char **argv);
//FT_LIBFT_C
long		ft_atoi(const char *str);
//FT_MUTEX_C
int			ft_mutex_create(t_data *dat);
int			ft_thread_create(t_data *dat, t_philo *philos);
//FT_PTHREAD_C
void		*ft_pthread_handler(void *arg);
//FT_ACTIONS_C
void		ft_slepping(t_philo *philo);
void		ft_thinking(t_philo *philo);
void		ft_dead(t_philo *philo);
void		*ft_take_forks(t_philo *philo, int first, int second);
void		*ft_leave_forks(t_philo *philo, int first, int second);
//FT_TIME_C
double		ft_time_diff(struct timeval *start, struct timeval *end);
struct timeval	ft_wait_time(struct timeval time, double time_wait);
double			ft_traslate_usec(int usec);

#endif