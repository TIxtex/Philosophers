#ifndef PHILOSOFERS_H
# define PHILOSOFERS_H
# include <unistd.h>	/*write(), usleep()*/
# include <stdio.h>		/*printf()*/
# include <stdlib.h>	/*malloc()*/
# include <string.h>	/*memset()*/
# include <sys/time.h>
# include <pthread.h>	/*pthread()*/
# include <semaphore.h>
# include <signal.h>
# include <limits.h>
# include <errno.h>
# include <sys/stat.h>
# include <fcntl.h>

struct s_data;

typedef struct s_philo
{
	pid_t			philo;
	long			last_eat;
	struct s_data	*dat;
}	t_philo;

typedef struct s_data
{
	int				finish;
	int				p_num;
	int				time_to_death;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	sem_t			*fork_sem;
	sem_t			*write_sem;
	sem_t			*finish_sem;
	long			i_time;
	t_philo			*philos;
}	t_data;

long		ft_atoi(const char *str);
size_t		ft_strlen(char *str);
int			semaphore_create(t_data *dat);
int			philos_create(t_data *dat, t_philo *philos);
void		*philo_handler(void *arg);
int			patrol(t_philo *philos);
int			slepping(t_philo *philo);
int			thinking(t_philo *philo);
int			ft_write(t_philo *philo, char *msg);
int			eat(t_philo *philo);
long		time_diff(long start, long end);
long		wait_time(long time_wait);
long		now_time(void);

#endif
