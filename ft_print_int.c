#include "printf.h"

static int	ft_size(unsigned int nbr)
{
	int	size;

	size = 0;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}

int	ft_print_int(int nbr)
{
	int	size;

	size = 0;
	ft_putnbr_fd(nbr, 1);
	if (nbr <= 0)
	{
		nbr *= -1;
		size++;
	}
	size += ft_size(nbr);
	return (size);
}