#include "philosofers.h"

long	time_diff(long start, long end)
{
	return (end - start);
}

long	now_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long	wait_time(long time_wait)
{
	register long	time_init;
	register long	time_now;

	time_init = now_time();
	if (-1 == time_init)
		return (time_init);
	time_now = time_init;
	while (time_wait > time_diff(time_init, time_now))
		time_now = now_time();
	return (time_now);
}
