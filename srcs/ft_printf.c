#include "ft_printf.h"
#include "libft.h"

contents *new_contents(const char *fmt, va_list ap, char *text)
{
	contents *cont;

	cont->text = text;
	cont->len = ft_strlen(text);
	cont->next = NULL;
	return cont;
}

static contents	parse(const char *fmt, va_list ap)
{
	contents cont;
	pflag *flag;

    flag = flag_consume(fmt);
	if (*fmt == 'c' || *fmt == '%')
		cont = new_contents(fmt, ap, fmt + 1);
	else if (*fmt == 's')
		cont = new_contents(fmt, ap, s_string(ap));
	else if (*fmt == 'd' || *fmt == 'i')
	 	cont = new_contents(fmt, ap, d_string(ap));
	else if (*fmt == 'u')
	    cont = new_contents(fmt, ap, u_string(ap));
	else if (*fmt == 'x')
		cont = new_contents(fmt, ap, x_string(ap));
	else if (*fmt == 'X')
		cont = new_contents(fmt, ap, X_string(ap));
    else if (*fmt == 'p')
        cont = new_contents(fmt, ap, p_string(ap));
	cont->pflag = flag;
	fmt++;
	return cont;
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
		    cur->next = new_contents(fmt, ap, TY_S, p - fmt);
		else if (*fmt == '%')
			cur->next = parse(++fmt, ap);
	    cur = cur->next;
	}
	va_end(ap);

	return concat_contents(head->next);
}

