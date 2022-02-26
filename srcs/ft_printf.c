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
		cont = new_contents(fmt, ap, s_to_string(ap));
	else if (*fmt == 'd' || *fmt == 'i')
	 	cont = new_contents(fmt, ap, d_to_string(ap));
	else if (*fmt == 'u')
	    cont = new_contents(fmt, ap, u_to_string(ap));
	else if (*fmt == 'x')
		cont = new_contents(fmt, ap, x_to_string(ap, 0));
	else if (*fmt == 'X')
		cont = new_contents(fmt, ap, x_to_string(ap, 1));
    else if (*fmt == 'p')
        cont = new_contents(fmt, ap, p_to_string(ap));
	cont->pflag = flag;
	fmt++;
	return cont;
}

char *extract_text(const char *fmt, size_t len)
{
    char *s;
    s = ft_calloc(1, len);
    while (len--)
        *s++ = *fmt++;
    return s;
}

size_t ft_printf(const char *fmt, ...)
{
	va_list	ap;
	contents head;
	contents *cur;
	char *p;
	char *text;

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
		    cur->next = new_contents(fmt, ap, extract_text(fmt, p-fmt));
		else if (*fmt == '%')
		    cur->next = parse(++fmt, ap);
	    cur = cur->next;
	}
	va_end(ap);
	return concat_contents(head->next);
}

