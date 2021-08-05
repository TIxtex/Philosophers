#include "../philosofers.h"

void	*ft_pthread_handler(void *arg)
{
	write(STDOUT_FILENO, "Hola\n", 5);
	(void) arg;
	return (NULL);
}
