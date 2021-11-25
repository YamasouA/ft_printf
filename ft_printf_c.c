// #include "libft.h"
#include "ft_printf.h"

int	put_chr(const char *fmt, va_list ap)
{
	char *c;
	
	c = va_arg(ap, char *);
	return ((int)write(1, &c, 1));
}