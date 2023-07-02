#include "philosofers.h"

void	*pthread_handler(void *arg)
{
	t_philo		*philo;
	int			i;

	philo = (t_philo *)arg;
	printf("%d - Inicio de las comidas\n", philo->philo_id);/*DEBUG*/
	i = 0;
	while (-1 == philo->dat->must_eat || i++ < philo->dat->must_eat)
	{
		eat(philo);//no puede comer si esta muerto
		slepping(philo);//esto lo va a hacer si o si if no ha muerto nadie
		thinking(philo);//aqui no hace nada, simplemente espera por los palillos if no ha muerto nadie
		if (!dead_door(philo))
			break ;
	}
	printf("%d - Fin de las comidas\n", philo->philo_id);/*DEBUG*/
	pthread_detach(philo->philo);
	return (NULL);
}