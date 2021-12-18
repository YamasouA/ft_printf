#include "ft_printf.h"

static int	parse(const char *fmt, va_list ap)
{
	if (*fmt == 'c')
		return (put_chr(ap));
	else if (*fmt == 's')
		return (put_str(ap));
	else if (*fmt == 'd' || *fmt == 'i')
	 	return (put_decimal(ap));
	else if (*fmt == 'u')
	        return (put_unsigned_decimal(ap));
	else if (*fmt == 'x')
		return (put_hex(ap, 0));
	else if (*fmt == 'X')
		return (put_hex(ap, 1));
    else if (*fmt == 'p')
        return (put_p(ap));
	else
	{
		write(1, "%", 1);
		return (1);
	}
}

int ft_printf(const char *fmt, ...)
{
	int	len;
	va_list	ap;

	len = 0;
	if (fmt == NULL)
		return (-1);
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			len += parse(fmt++, ap);
		}
		else
			len += write(1, fmt++, 1);
	}
	va_end(ap);
	return (len);
}
