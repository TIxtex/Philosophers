/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_races.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:13:16 by uliherre          #+#    #+#             */
/*   Updated: 2023/10/13 20:13:17 by uliherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

long	av(t_share *v)
{
	long	tmp;

	pthread_mutex_lock(&v->mutex_var);
	tmp = v->var;
	pthread_mutex_unlock(&v->mutex_var);
	return (tmp);
}

void	mv(t_share *v, long value)
{
	pthread_mutex_lock(&v->mutex_var);
	v->var = value;
	pthread_mutex_unlock(&v->mutex_var);
}
