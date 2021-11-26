#include "ft_printf.h"

int	put_chr(va_list ap)
{
	char *c;
	
	c = va_arg(ap, char *);
	write(1, &c, 1);
	return (1);
}