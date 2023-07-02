#include "philosofers.h"

long	time_diff(long start, long end)
{
	return (end - start);
}

long	now_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long	wait_time(long time_wait)
{
	long	time_init;
	long	time_now;

	time_init = now_time();
	time_now = time_init;
	while (time_wait > time_diff(time_init, time_now))
		time_now = now_time();
	return (time_now);
}
