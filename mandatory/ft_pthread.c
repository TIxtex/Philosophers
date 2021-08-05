#include "../philosofers.h"

void	*ft_pthread_handler(void *arg)
{
	printf("Hola, soy el filosofo nºx\n");
	(void) arg;
	return (NULL);
}
