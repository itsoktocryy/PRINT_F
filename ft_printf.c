#include "ft_printf.h"

static char ft_check_flag(char str)
{
    if (str == 'c' || str == 's' || str == 'd'
        || str == 'i' || str == 'u' || /*str =='p'
        || str == 'x' || str == 'X' ||*/ str == '%')
        return (1);
    else
        return (0);
}

static int  ft_print_flag(char str, va_list ap)
{
    int len;
    
    len = 0;
    if (str == 'c' || str == 's')
        len = ft_print_char(va_arg(ap, char *), str);
    else if (str == 'd' || str == 'i')
        len = ft_print_int(va_arg(ap, int));
    else if (str == 'u')
        len = ft_print_uint(va_arg(ap, unsigned int));
    /*else if (str == 'x' || str == 'X')
        len = ft_print_hexa(va_arg(ap, unsigned int));
    else if (str == 'p')
        len = ft_print_void(va_arg(ap, unsigned long long));
    else if (str == '%')*/
	    write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	ap;

	va_start(ap, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!ft_check_flag(str[i + 1]))
				return (0);
			len += ft_print_flag(str[i + 1], ptr);
			i++;
		}
		else
		{
			len += ft_putchar_fd(str[i], 1);
			len++;
			i++;
		}
	}
	va_end(ap);
	return (len);
}
