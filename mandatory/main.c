#include "../philosofers.h"

int	main(int argc, char **argv)
{
	t_data	dat;
	t_philo	*philos;

	if (ft_check_arg(argc, argv))
		return (-1);
	ft_asing_arg(&dat, argc, argv);
	if (ft_mutex_create(&dat))
		return (-1);
	philos = NULL;
	
	if (ft_thread_create(&dat, philos))
		return (-1);
	while (1)
		sleep(0);
	free(dat.mutex);
	return (0);
}

void	ft_end_of_program(t_data *dat)
{
	(void)dat;
}
