#include "printf.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>


static size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}

int	ft_print_char(char *str, char c)
{
	if (c == 'c')
	{
		write (1, &str, 1);
		return (1);
	}
	else
	{
		if (!str)
		{
			ft_putstr_fd("(null)", 1);
			return (6);
		}
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	return (0);
}