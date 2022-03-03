#include "ft_printf.h"
#include "libft.h"

contents *new_contents(const char *fmt, va_list ap, char *text)
{
	contents *cont;

	cont->text = text;
	cont->len = ft_strlen(text);
	cont->next = NULL;
	cont->flag = NULL;
	return cont;
}

char	*flag_char(char c, size_t n)
{
	char *str;

	while (n--)
		*str++ = c;
	return str;
}

char *apply_flag(char *str, pflag flag)
{
	if (flag->is_alignleft)
		return ft_strjoin(flag_char(' ', ft_strlen(str)), str);
	if (flag->is_padding)
		return ft_strjoin();
	if (flag->is_precision)
	    return ft_strjoin();
	if (flag->is_specifier)
		return ft_strjoin();
	if (flag->is_alignspace)
	{
		if (*str == '-')
			return str;
		return ft_strjoin(' ', str);
	}
	if (flag->is_assign)
	{
		if (*str == '-')
			return str;
		return ft_strjoin('+', str);
	}
}

pflag *flag_consume(const char *fmt)
{

}

static contents	parse(const char *fmt, va_list ap)
{
	contents cont;
	pflag *flag;
	char	*str;

    flag = flag_consume(fmt);
	if (*fmt == 'c' || *fmt == '%')
		str = *fmt;
	else if (*fmt == 's')
		str = s_to_string(ap);
	else if (*fmt == 'd' || *fmt == 'i')
	 	str = d_to_string(ap);
	else if (*fmt == 'u')
	    str = u_to_string(ap);
	else if (*fmt == 'x')
		str = x_to_string(ap, 0);
	else if (*fmt == 'X')
		str = x_to_string(ap, 1);
    else if (*fmt == 'p')
        str = p_to_string(ap);
	cont = apply_flag(str, flag);
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

void free_contents(contents *list)
{
	contents *tmp;

	while (list != NULL)
	{
        tmp = list->next;
		free(list->text);
		free(list->pflag);
		free(list);
		list = tmp;
	}
}

void apply_flag(contents *list)
{
	if (list->flag->is_alignleft)
	    apply_alignleft(list);
	if (list->flag->is_padding)
	    apply_padding(list)
	if (list->flag->is_precision)
	    apply_precision(list);
	if (list->flag->is_specifier)
	    apply_specifier(list);
	if (list->flag->is_alignspace)
	    apply_alignspace(list);
	if (list->flag->is_assign)
	    apply_assign(list);
}

int concat_contents(contents *list)
{
	int len;
	contents *list_cpy;

    len = 0;
	list_cpy = list;
	while (list_cpy != NULL)
    {
        if (list_cpy->flag != NULL)
		    apply_flag(list_cpy);
		len += list_cpy->len;
		ft_putstr_fd(list->text, 1);
		list_cpy = list_cpy->next;
	}
	free_contents(list);
	return len;
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
		while (*p != '%')
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