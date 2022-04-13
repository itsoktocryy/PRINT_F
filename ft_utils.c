#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return(c);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}

int ft_hexa_len(unsigned long long nbr)
{
    int len;

    len = 0;
    if (nbr == 0)
        len++;
    while (nbr > 0)
    {
        nbr = nbr / 16;
        len++;
    }
    return (len);
}
