#include "../includes/ft_printf.h"


// contents *new_contents(const char *fmt, va_list ap, char *text)
// {
// 	contents *cont;

// 	cont->text = text;
// 	cont->len = ft_strlen(text);
// 	cont->next = NULL;
// 	cont->flag = NULL;
// 	return cont;
// }

char	*flag_char(char *str1, char c, size_t n)
{
	char *str;
	size_t	idx;
	size_t	len;

	len = n - ft_strlen(str1);
	if (len <= 0)
		return (NULL);
	str = (char *)ft_calloc(len, 1);
	idx = n;
	while (n--)
		str[idx-n] = c;
	return str;
}

// 直せ
char	*ft_insert(char *str, char *str2, size_t n)
{
	size_t	str_len;
	size_t	str2_len;
	size_t	cnt;
	char *str_join;

	str_len = ft_strlen(str);
	str2_len = ft_strlen(str2);
	str_join = (char *)ft_calloc(str_len + str2_len, 1);
	if (!str_join)
		return (NULL);
	cnt = 0;
	while (str_len--)
	{
		if (cnt == n)
		{
			*str_join++ = *str2++;
			str2_len--;
		}
		*str_join++ = *str++;
		cnt++;
	}
	while (str2_len--)
		*str_join++ = *str2++;
	return str;
}

char *sss()
{
	return "c";
}
// char *apply_padding(char *str, pflag *flag)
// {
// 	if (flag->padding_n <= ft_strlen(str))
// 		return str;
// 	if (*str != '-')
// 		str = ft_strjoin(flag_char('0', flag->padding_n - ft_strlen(str)), str);
// 	return ft_insert(str, flag_char('0', flag->padding_n - ft_strlen(str)), 1);
// }

// char *apply_precision(char *str, pflag *flag)
// {
// 	if (flag->precision_n <= ft_strlen(str))
// 		return str;
// 	if (*str != '-')
// 		str = ft_strjoin(flag_char('0', flag->precision_n - ft_strlen(str)), str);
// 	return ft_insert(str, flag_char('0', flag->precision_n - ft_strlen(str)), 1);
// }

char *apply_width(char *str1, char *str2, int insert)
{
	char	*str;

	if (!str1 || !str2)
		return (NULL);
	str = (char *)ft_calloc(ft_strlen(str1) + ft_strlen(str2), 1);
	if (insert==1)
		str = ft_insert(str1, str2, 1);
	else
		str = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (str);
}

char	*str_to_hex(char *str)
{
	return str;
}
char	*apply_convert(char *str, pflag *flag)
{
	if (*flag->convert == 'o')
		return str_to_hex(str);
	return str;
}

char *apply_flag(char *str, pflag *flag)
{
	if (flag->is_alignleft) // '-'
		str = apply_width(str, flag_char(str, ' ', flag->field_width), 0);
	if (flag->is_padding) // '0'
		// str = apply_padding(str, flag); // strの先頭が-かどうかで処理が変わる
		str = apply_width(str, flag_char(str, '0', flag->field_width), 1);
	if (flag->is_precision) // '.'
		str = apply_width(str, flag_char(str, '0', flag->field_width), 1);
	// if (flag->is_specifier) // '#'
	// 	str = apply_convert(str, flag);;
	// if (flag->is_alignspace) // ' '
	// 	if (*str != '-')
	// 		str = ft_strjoin(" ", str);
	// if (flag->is_assign) // +
	// 	if (*str != '-')
	// 		str = ft_strjoin("+", str);
	return str;
}

size_t consume_n(const char *fmt)
{
	int base;
	size_t n;

	base = 1;
	n = 0;
	if (*fmt == '-')
		return n;
	while (*fmt)
	{
		if (*fmt >= '0' && *fmt <= '9')
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

	flag = ft_calloc(1, sizeof(pflag));
	if (!flag)
		return (NULL);
	flag->is_alignleft = 0;
	flag->is_padding = 0;
	flag->is_precision = 0;
	flag->is_specifier = 0;
	flag->is_alignspace = 0;
	flag->is_assign = 0;
	flag->convert = NULL;
	flag->field_width = 0;
	flag->precision = 0;
	return flag;
}

pflag *flag_consume(const char *fmt)
{
	pflag	*flag;

	flag = init_flag();
	if (!flag)
		return (NULL);
	while (*fmt)
	{
		if (*fmt == '-')
		{
			flag->is_alignleft = 1;
			flag->field_width = consume_n(fmt);
		}
		else if (*fmt == '0')
		{
			flag->is_padding = 1;
			flag->field_width = consume_n(fmt);
		}
		else if (*fmt == '.')
		{
			flag->is_precision = 1;
			flag->precision = consume_n(fmt);
		}
		// else if (*fmt == '#')
		// {
		// 	flag->is_specifier = 1;
		// 	flag->convert = *(++fmt);
		// }
		// else if (*fmt == ' ')
		// {
		// 	flag->is_alignspace = 1;
		// 	flag->alignspace_n = consume_n(fmt);

		// }
		// else if (*fmt == '+')
		// 	flag->is_assign = 1;
		fmt++;
	}
	return flag;
}

size_t	write_str(char *str)
{
	ft_putstr_fd(str, 1);
	free(str);
	return ft_strlen(str);
}

pflag *flag_priority(pflag *flag)
{
	if (flag == NULL)
		return (NULL);
	if (flag->is_alignleft && flag->is_padding)
		flag->is_padding = false;
	return (flag);
}

size_t	parse(const char *fmt, va_list ap)
{
	// contents cont;
	pflag *flag;
	char	*str;

    flag = flag_consume(fmt);
	flag = flag_priority(flag);
	if (!flag)
		return (-1);
	if (*fmt == 'c' || *fmt == '%')
		str = (char *)fmt;
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
	else // 適当
		str = (char *)fmt;
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
	total_len += write_len;
	if (total_len < tmp)
		return (1);
	return (0);
}

int ft_printf(const char *fmt, ...)
{
	va_list	ap;
	// contents head;
	// contents *cur;
	char *p;
	// char *text;
	int	total_len;
	int write_len;


	// head->next = NULL;
	// cur = &head;
	if (fmt == NULL)
		return (-1);
	total_len = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		p = (char *)fmt;
		while (*p != '%' && *p)
		    p++;
		if (p != fmt)
		    write_len = extract_text(fmt, p-fmt);
		else // *fmt == '%'
		    write_len = parse(++fmt, ap);
	    if (write_len < 0 || check_len(write_len, total_len))
			return (-1);
		total_len += write_len;
	}
	va_end(ap);
	return (total_len);
}