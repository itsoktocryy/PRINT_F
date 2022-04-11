#include "printf.h"
#include <unistd.h>
static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = n * -1;
		ft_putchar_fd('-', fd);
	}
	else
		nb = n;
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		nb %= 10;
	}
	ft_putchar_fd(nb + '0', fd);
}

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