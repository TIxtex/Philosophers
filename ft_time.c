#include "philosofers.h"

double	ft_traslate_usec(int usec)
{
	return (1e-6 * usec);
}

double	ft_time_diff(struct timeval start, struct timeval end)
{
	return ((end.tv_sec - start.tv_sec)
		+ 1e-6 * (end.tv_usec - start.tv_usec));
}

struct timeval	ft_wait_time(struct timeval time, double time_wait)
{
	struct timeval	time_init;
	struct timeval	time_now;

	time_init = time;
	time_now = time;
	while (time_wait > ft_time_diff(time_init, time_now))
		gettimeofday(&time_now, NULL);
	return (time_now);
}
