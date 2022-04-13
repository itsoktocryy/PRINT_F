#include "ft_printf.h"

static void ft_put_ptr(unsigned long long nbr)
{
	if (nbr >= 16)
	{
		ft_put_ptr(nbr / 16);
		ft_put_ptr(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd(nbr + '0', 1);
		else
			ft_putchar_fd((nbr - 10 + 'a'), 1);
	}
}

int ft_print_adr(unsigned long long nbr)
{
    ft_putstr_fd("0x", 1);
    ft_put_ptr(nbr);
    return (ft_hexa_len(nbr));
}
