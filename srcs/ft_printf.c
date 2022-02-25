#include "ft_printf.h"

static int	parse(const char *fmt, va_list ap)
{
	char *s;
	if (*fmt == 'c')
		new_contents();
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
	else if (is_flag)
	    
	else
	{
		write(1, "%", 1);
		return (1);
	}
	fmt++;
	return new_contents;
}

int ft_printf(const char *fmt, ...)
{
	va_list	ap;
	contents head;
	contents *cur;
	char *p;

	head->next = NULL;
	cur = &head;
	if (fmt == NULL)
		return (-1);
	va_start(ap, fmt);
	while (*fmt)
	{
		p = fmt;
		while (is_alnum(p))
		    p++;
		if (p != fmt)
		    cur->next = new_contents(fmt, TY_S, p - fmt);
		else if (*fmt == '%')
		{
			cur->next = parse(++fmt, ap);
			cur = cur->next;
		}
	    cur = cur->next;
	}
	va_end(ap);

	return concat_contents(head->next);
}

