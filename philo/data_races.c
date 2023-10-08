#include "philosofers.h"

long	av(t_share v)
{
	long	tmp;

	if (pthread_mutex_lock(&v.mutex_var))
		exit (errno);
	tmp = v.var;/*ojito con esto depurar*/
	if (pthread_mutex_unlock(&v.mutex_var))
		exit (errno);
	return (tmp);
}

void	mv(t_share *v, long value)
{
	if (pthread_mutex_lock(&v->mutex_var))
		exit (errno);
	v->var = value; /*esto puede que no se este guardando bien tengo que depurar*/
	if (pthread_mutex_unlock(&v->mutex_var))
		exit (errno);
}
