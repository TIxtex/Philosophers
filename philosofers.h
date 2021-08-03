#ifndef PHILOSOFERS_H
# define PHILOSOFERS_H
# include <unistd.h>//write(), usleep(),
# include <stdio.h>//printf()
# include <stdlib.h>//malloc()
# include <string.h>//memset()
# include <sys/time.h>//gettimeofday
#include <pthread.h>//pthread

typedef struct s_data
{
	int				p_num;
	int				time_to_death;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	struct timeval	i_time;
}				t_data;

//FT_CHECK_ARG_C
int		ft_check_arg(int argc, char **argv);
void	ft_asing_arg(t_data *dat, int argc, char **argv);
//FT_LIBFT_C
long	ft_atoi(const char *str);

#endif