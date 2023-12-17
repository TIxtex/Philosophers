/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:12:57 by uliherre          #+#    #+#             */
/*   Updated: 2023/10/13 20:12:58 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

long	now_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	wait_time(long time_wait)
{
	register long	time_init;

	time_init = now_time();
	while (time_wait > now_time() - time_init)
		usleep(50);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	register char	*nw_str;
	register char	*start;
	size_t			len_1;
	size_t			len_2;

	if (NULL == s1 || NULL == s2)
		return (NULL);
	len_1 = ft_strlen((char *) s1);
	len_2 = ft_strlen((char *) s2);
	nw_str = (char *)malloc((len_1 + len_2 + 1) * sizeof(char));
	start = nw_str;
	if (NULL != nw_str)
	{
		while ('\0' != *s1)
			*(nw_str++) = *(s1++);
		while ('\0' != *s2)
			*(nw_str++) = *(s2++);
		*nw_str = '\0';
	}
	return (start);
}
