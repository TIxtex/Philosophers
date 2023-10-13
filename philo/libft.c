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
			nbr_of_neg *= -1;
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
