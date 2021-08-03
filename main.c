#include "philosofers.h"

int	main(int argc, char **argv)
{
	t_data	dat;

	printf("adios mundo\n");
	if (ft_check_arg(argc, argv))
		return (-1);
	ft_asing_arg(&dat, argc, argv);
	return (0);
}
