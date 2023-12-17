/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:13:09 by uliherre          #+#    #+#             */
/*   Updated: 2023/10/13 20:13:10 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

static int get_length(long n)
{
    int length = 0;
    
    if (n == 0)
        return (1);
    if (n < 0)
	{
		n = -n;
		length++;
	}
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char *ft_itoa(long n)
{
	register int	i;
	int				length;
	char			*result;
	
	length = get_length(n);
	if (n < 0)
		length++;
	result = (char *) malloc((length + 1) * sizeof(char));
	if (NULL == result)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	i = length - 1;
	while (i-- >= 0)
	{
		result[i] = '0' + (n % 10);
		n /= 10;
	}
	result[length] = '\0';
	return (result);
}

void	ft_error(const char *errstr, int errnum)
{
	write (STDERR_FILENO, errstr, sizeof(errstr));
	exit (errnum);
}

long	ft_atoi(const char *str)
{
	int		nbr_of_neg;
	long	returned;

	returned = 0;
	nbr_of_neg = 1;
	while (*str == ' ' || (unsigned)*str - '\t' < 5)
		str++;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			nbr_of_neg = -nbr_of_neg;
	while ((unsigned)*str - '0' < 10)
		returned = (returned * 10) + (*(str++) - 48);
	return (returned * nbr_of_neg);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}
