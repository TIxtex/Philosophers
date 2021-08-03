#include "../philosofers.h"

long	ft_atoi(const char *str)
{
	int		nbr_of_neg;
	long	returned;

	returned = 0;
	nbr_of_neg = 1;
	while (*str == ' ' || (unsigned)*str - '\t' < 5)
		str++;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			nbr_of_neg *= -1;
	while ((unsigned)*str - '0' < 10)
		returned = (returned * 10) + (*(str++) - 48);
	return (returned * nbr_of_neg);
}
