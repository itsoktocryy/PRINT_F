#include "ft_printf.h"

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
			return (0);
		}
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	return (0);
}