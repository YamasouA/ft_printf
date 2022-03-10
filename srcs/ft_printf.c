#include "ft_printf.h"


// contents *new_contents(const char *fmt, va_list ap, char *text)
// {
// 	contents *cont;

// 	cont->text = text;
// 	cont->len = ft_strlen(text);
// 	cont->next = NULL;
// 	cont->flag = NULL;
// 	return cont;
// }

char	*flag_char(char c, size_t n)
{
	char *str;
	char *tmp;

	tmp = str;
	while (n--)
		*str++ = c;
	return tmp;
}

char *apply_padding(char *str, pflag *flag)
{
	if (flag->padding_n <= ft_strlen(str))
		return str;
	if (*str != '-')
		str = ft_strjoin(flag_char('0', flag->padding_n - ft_strlen(str)), str);
	return ft_insert(str, flag_char('0', flag->padding_n - ft_strlen(str)), 1);
}

char *apply_precision(char *str, pflag *flag)
{
	if (flag->precision_n <= ft_strlen(str))
		return str;
	if (*str != '-')
		str = ft_strjoin(flag_char('0', flag->precision_n - ft_strlen(str)), str);
	return ft_insert(str, flag_char('0', flag->precision_n - ft_strlen(str)), 1);
}

char	*apply_convert(char *str, pflag *flag)
{
	if (flag->convert == 'o')
		return str_to_hex();
	if (flag->convert == '')
		return ;
}

char *apply_flag(char *str, pflag *flag)
{
	if (flag->is_alignleft) // '-'
		str = ft_strjoin(str, flag_char(' ', flag->alignleft_n - ft_strlen(str)));
	if (flag->is_padding) // '0'
		str = apply_padding(str, flag); // strの先頭が-かどうかで処理が変わる
			//return ft_strjoin(flag_char('0', flag->padding_n - ft_strlen), str);
	if (flag->is_precision) // '.'
		str = apply_precision(str, flag);
	if (flag->is_specifier) // '#'
		str = apply_convert(str, flag);;
	if (flag->is_alignspace) // ' '
		if (*str != '-')
			str = ft_strjoin(' ', str);
	if (flag->is_assign) // +
		if (*str != '-')
			str = ft_strjoin('+', str);
	return str;
}

size_t consume_n(const char *fmt)
{
	int base;
	size_t n;

	base = 1;
	while (*fmt)
	{
		if (*fmt => '0' && *fmt <= '9')
		{
			n += *fmt - '0' * base;
			base *= 10;
		}
		else
			break;
	}
	return n;
}

pflag *init_flag()
{
	pflag	*flag;

	flag->is_alignleft = 0;
	flag->is_padding = 0;
	flag->is_precision = 0;
	flag->is_specifier = 0;
	flag->is_alignspace = 0;
	flag->is_assign = 0;
	flag->convert = NULL;
	flag->precision_n = 0;
	flag->padding_n = 0;
	flag->alignleft_n = 0;
	flag->alignspace_n = 0;
	return flag;
}

pflag *flag_consume(const char *fmt)
{
	pflag	*flag;

	flag = init_flag();
	while (*fmt)
	{
		if (*fmt == '-')
		{
			*flag->is_alignleft = 1;
			*flag->alignleft_n = consume_n(fmt);
		}
		else if (*fmt == '0')
		{
			*flag->is_padding = 1;
			*flag->padding_n = consume_n(fmt);
		}
		else if (*fmt == '.')
		{
			*flag->is_precision = 1;
			*flag->precision_n = consume_n(fmt);
		}
		else if (*fmt == '#')
		{
			*flag->is_convert = 1;
			*flag->convert = consume_c(fmt);
		}
		else if (*fmt == ' ')
		{
			*flag->is_alignspace = 1;
			*flag->alignspace_n = consume_n(fmt);

		}
		else if (*fmt == '+')
			*flag->is_assign = 1;
	}
	return flag;
}

size_t	write_str(char *str)
{
	ft_putstr_fd(str, 1);
	free(str);
	return ft_strlen(str);
}

size_t	parse(const char *fmt, va_list ap)
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
	str = apply_flag(str, flag);
	fmt++;
	return write_str(str);
}

size_t extract_text(const char *fmt, size_t len)
{
    char *str;

    str = ft_calloc(1, len);
    while (len--)
        *str++ = *fmt++;
	
	return write_str(str);
}

// void free_contents(contents *list)
// {
// 	contents *tmp;

// 	while (list != NULL)
// 	{
//         tmp = list->next;
// 		free(list->text);
// 		free(list->pflag);
// 		free(list);
// 		list = tmp;
// 	}
// }

// int concat_contents(contents *list)
// {
// 	int len;
// 	contents *list_cpy;

//     len = 0;
// 	list_cpy = list;
// 	while (list_cpy != NULL)
//     {
//         if (list_cpy->flag != NULL)
// 		    apply_flag(list_cpy);
// 		len += list_cpy->len;
// 		ft_putstr_fd(list->text, 1);
// 		list_cpy = list_cpy->next;
// 	}
// 	free_contents(list);
// 	return len;
// }

int check_len(int total_len, size_t write_len)
{
	int tmp;

	tmp = total_len;
	if (total_len + write_len < total_len)
		return (1);
	return (0);
}

int ft_printf(const char *fmt, ...)
{
	va_list	ap;
	// contents head;
	// contents *cur;
	char *p;
	char *text;
	int	total_len;
	int write_len;


	// head->next = NULL;
	// cur = &head;
	if (fmt == NULL)
		return (-1);
	va_start(ap, fmt);
	while (*fmt)
	{
		p = fmt;
		while (*p != '%' & *p)
		    p++;
		if (p != fmt)
		    write_len = extract_text(fmt, p-fmt)
		else // *fmt == '%'
		    write_len = parse(++fmt, ap);
	    if (write_len < 0 || check_len(write_len, total_len))
			return (-1);
		total_len += write_len;
	}
	va_end(ap);
	return (total_len);
}