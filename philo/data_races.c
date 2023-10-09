#include "philosofers.h"

long	av(t_share *v)
{
	long	tmp;

	pthread_mutex_lock(&v->mutex_var);
	tmp = v->var;/*ojito con esto depurar*/
	pthread_mutex_unlock(&v->mutex_var);
	return (tmp);
}

void	mv(t_share *v, long value)
{
	pthread_mutex_lock(&v->mutex_var);
	v->var = value; /*esto puede que no se este guardando bien tengo que depurar*/
	pthread_mutex_unlock(&v->mutex_var);
}
