#include "philosofers.h"

double	ft_usec(int sec)
{
	return (1e-6 * sec);
}

double	ft_time_diff(struct timeval start, struct timeval end)
{
	return ((end.tv_sec - start.tv_sec)
		+ 1e-6 * (end.tv_usec - start.tv_usec));
}

struct timeval ft_time_add(struct timeval source, struct timeval add)
{
	struct timeval	aux;

	aux.tv_sec = source.tv_sec + add.tv_sec;
	aux.tv_sec = source.tv_sec + add.tv_sec;
	if (aux.tv_usec >= 1000000)
	{
		aux.tv_sec += 1;
		aux.tv_usec -= 1000000;
	}
	return (aux);
}

struct timeval	ft_wait_time(struct timeval time, double time_wait)
{
	struct timeval	time_init;
	struct timeval	time_now;

	time_init = time;
	time_now = time;
	while (time_wait > ft_time_diff(time_init, time_now))
		gettimeofday(&time_now, NULL);
	time_now.tv_sec = 0;
	time_now.tv_usec = time_wait;
	time_now = ft_time_add(time_init, time_now);//

	return (time_now);
}
