#include "philosofers.h"

int	av(t_share *v, long *value)
{
	long	*v_aux;

	v_aux = (long *) malloc(sizeof(long));
	if (NULL == v_aux)
		return (errno);
	if (pthread_mutex_lock(&v->mutex_var))
		return (errno);
	*v_aux = v->var;/*ojito con esto depurar*/
	if (pthread_mutex_unlock(&v->mutex_var))
		return (errno);
	return (EXIT_SUCCESS);
}

int mv(t_share *v, long *value)
{
	if (pthread_mutex_lock(&v->mutex_var))
		return (errno);
	v->var = *value; /*esto puede que no se este guardando bien tengo que depurar*/
	if (pthread_mutex_unlock(&v->mutex_var))
		return (errno);
	return (EXIT_SUCCESS);
}