#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>

int	    ft_printf(const char *str, ...);

int	    ft_print_char(char *str, char c);
int	    ft_print_int(int nbr);
int	    ft_print_uint(unsigned int nbr);
int     ft_print_hexa(unsigned int nbr, const char format);

int 	ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char *s, int fd);

#endif