/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_races.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:13:16 by uliherre          #+#    #+#             */
/*   Updated: 2023/10/26 19:04:02 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

long	av(t_share *v)
{
	long	tmp;

	if (sem_wait(v->sem_var))
		exit (-11);
	tmp = v->var;
	if (sem_post(v->sem_var))
		exit (-11);
	return (tmp);
}

void	mv(t_share *v, long value)
{
	if (sem_wait(v->sem_var))
		exit (-11);
	v->var = value;
	if (sem_post(v->sem_var))
		exit (-11);
}
