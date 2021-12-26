#include "philosofers.h"

logn long	ft_time_diff(long long start, long long end)
{
	return (end - start);
}

long long	ft_now_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	ft_wait_time(long long time_wait)
{
	long long	time_init;
	long long	time_now;

	time_init = ft_now_time();
	time_now = time_init;
	while (time_wait > ft_time_diff(time_init, time_now))
		time_now = ft_now_time();
	return (time_now);
}
