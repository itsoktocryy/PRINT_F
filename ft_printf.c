#include "ft_printf.h"

static char ft_check_flag(char str)
{
    if (str == 'c' || str == 's' || str == 'd'
        || str == 'i' || str == 'u' || str =='p'
        || str == 'x' || str == 'X' || str == '%')
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
    else if (str == 'x' || str == 'X')
        len = ft_print_hexa(va_arg(ap, unsigned int), str);
    else if (str == 'p')
        len = ft_print_adr(va_arg(ap, unsigned long long));
    else if (str == '%')
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
			len += ft_print_flag(str[i + 1], ap);
			i += 2;
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

#include <stdio.h>
int main()
{
	char e1[] = "1312";
	char *e2 = NULL; //= Daddyimstuck;
	char e3 = '$';
	unsigned int e4 = 99999999;
	int e5 = 1312;
	int e6 = 13121312;

	ft_printf("ft_printf : Mem address is %p\n", &e1);
	printf("printf : Mem address is %p\n\n", &e1);

	ft_printf("ft_printf : String is %s\n", e2);
	printf("printf : String is %s\n\n", e2);

	ft_printf("ft_printf : Character is %c\n", e3);
	printf("printf : Character is %c\n\n", e3);
		
	ft_printf("ft_printf : Number is %u\n", e4);
	printf("printf : Number is %u\n\n", e4);

	ft_printf("ft_printf : Number %08d\n", e5);
	printf("printf : Number %08d\n\n", e5);

	ft_printf("ft_printf : Number %i\n", e5);
	printf("printf : Number %i\n\n", e5);

	ft_printf("ft_printf : Hexadecimal convertion is %x\n", e6);
	printf("printf : Hexadecimal convertion is %x\n", e6);
	ft_printf("ft_printf : Hexadecimal convertion is %X\n\n",e6);
}

		// else if (str[i + 1] >= 48 && str[i + 1] <= 57)
		// {
		// 	len += ft_putchar_fd('0', 1);
		// 	len++;
		// 	i++;
		// }