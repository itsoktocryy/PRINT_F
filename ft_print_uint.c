#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

static int	ft_size(unsigned int nb)
{
	int	size;

	size = 1;
	if (nb < 0)
	{
		nb *= -1;
		size++;
	}
	while (nb >= 10)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

static char	*ft_utoa(unsigned int n)
{
	int		size;
	char	*str;

	size = ft_size(n);
	str = malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (0);
	while (n != 0)
	{
		str[size - 1] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	return (str);
}

int	ft_print_uint(unsigned int nbr)
{
	char	*str;
	int		size;

	size = 0;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (nbr < 0)
		nbr *= -1;
	str = ft_utoa(nbr);
	ft_putstr_fd(str, 1);
	size = ft_strlen(str);
	free(str);
	return (size);
}