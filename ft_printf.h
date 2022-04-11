#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_print_char(char *str, char c);
int	ft_print_int(int nbr);
int	ft_print_uint(unsigned int nbr);

#endif