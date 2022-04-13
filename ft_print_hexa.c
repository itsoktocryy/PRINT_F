#include "ft_printf.h"

static int ft_len(unsigned int nbr)
{
    int len;

    len = 0;
    while (nbr != 0)
    {
        nbr = nbr / 16;
        len++;
    }
    return (len);
}

static void ft_put_hexa(unsigned int nbr, const char format)
{
    if (nbr >= 16)
    {
        ft_put_hexa(nbr / 16, format);
        ft_put_hexa(nbr % 16, format);
    }
    else
    {
        if (nbr <= 9)
            ft_putchar_fd(nbr + '0', 1);
        else
        {
            if (format == 'x')
                ft_putchar_fd((nbr - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((nbr - 10 + 'A'), 1);
        }
    }
}

int ft_print_hexa(unsigned int nbr, const char format)
{
    if (nbr == 0)
        ft_putchar_fd('0', 1);  //write(1, "0", 1);
    else
        ft_put_hexa(nbr, format);
    return (ft_len(nbr));
}
