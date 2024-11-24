#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

int		print_p(unsigned long n);
int		print_string(char *str);
int		print_int(int n);
int		print_unsigned_int(unsigned int n);
int		ft_printf(const char *format, ...);
char	*ft_itoa_unsigned(unsigned int n);
int		hex_len(unsigned int n);
void	dectohex(unsigned int n, char format);
int		put_hex(unsigned int n, char format);
int		pointerhex(unsigned long n, int i);

#endif
