#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
int ft_printf(const char *fmt, ...);
int	put_chr(va_list ap);
int	put_str(va_list ap);
int	put_decimal(va_list ap);
int put_unsigned_decimal(va_list ap);
int put_hex(va_list ap, int size);
int put_p(va_list ap, int size);

#endif