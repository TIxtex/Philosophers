#include "philosofers.h"

double	ft_time_diff(long long start, long long end)
{
	return (end - start);
}

long long ft_now_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
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
