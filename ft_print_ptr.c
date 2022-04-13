#include "ft_printf.h"

static int ft_len(unsigned long long nbr)
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

void ft_put_ptr(unsigned long long nbr)
{
	if (nbr >= 16)
	{
		ft_print_ptr(nbr / 16);
		ft_print_ptr(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd(nbr + '0', 1);
		else
			ft_putchar_fd((nbr - 10 + 'a'), 1);
	}
}

int ft_print_ptr(unsigned long long nbr)
{
    ft_putstr_fd("0x", 1);
    ft_put_ptr(nbr);
    return (ft_len(nbr));
}
