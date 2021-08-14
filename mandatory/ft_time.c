#include "../philosofers.h"

double	ft_time_diff(struct timeval *start, struct timeval *end)
{
	return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}

void	ft_wait_time(t_philo *philo, int time_wait)
{
	struct timeval	time_now;

	gettimeofday(&time_now, NULL);
	philo->dat->aux_time->tv_sec = time_now.tv_sec;
	philo->dat->aux_time->tv_usec = time_now.tv_usec;
	while (time_wait > ft_time_diff(&philo->dat->aux_time, &time_now))
		gettimeofday(&time_now, NULL);
}
