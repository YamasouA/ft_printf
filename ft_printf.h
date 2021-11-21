#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
int ft_printf(const char *fmt, ...);
void	ft_putnbr_fd(int n, int fd);
int	put_chr(const char *fmt, va_list ap);
int put_hex(const char *fmt, va_list ap, int size);
int	put_str(const char *fmt, va_list ap);
ssize_t	put_decimal(const char *fmt, va_list ap);
int     put_unsigned_decimal(const char *fmt, va_list ap);
