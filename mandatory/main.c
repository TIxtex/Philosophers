#include "../philosofers.h"

int	main(int argc, char **argv)
{
	t_data	dat;

	if (ft_check_arg(argc, argv))
		return (-1);
	ft_asing_arg(&dat, argc, argv);
	if (ft_mutex_create(&dat))
		return (-1);
	if (ft_thread_create(&dat))
		return (-1);
	//Aqui ya estan los hilos creados y unidos poner bucle;
	return (0);
}

void	ft_end_of_program(t_data *dat)
{
	free(dat->mutex);
}
