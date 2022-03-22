#include "../includes/ft_printf.h"

size_t	write_str(char *str, int c_null)
{
	size_t	len;

	if (!str)
		return (1);
	len = ft_strlen(str);
	if (c_null)
		len = 1;
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

size_t	parse(const char **fmt, va_list *ap)
{
	pflag *flag;
	char	*str;
	const char	*fmt_tmp;
	int	c_null;

	fmt_tmp = *fmt;
	c_null = 0;
    flag = consume(&fmt_tmp);
	// flag = flag_priority(flag);
	if (!flag)
		return (LONG_MAX);
	if (*fmt_tmp == 'c')
		str = c_to_string(va_arg(*ap, int), &c_null);
	else if (*fmt_tmp == '%')
		str = c_to_string('%', &c_null);
	else if (*fmt_tmp == 's')
		str = s_to_string(ap);
	else if (*fmt_tmp == 'd' || *fmt_tmp == 'i')
	 	str = d_to_string(ap);
	else if (*fmt_tmp == 'u')
	    str = u_to_string(ap);
	else if (*fmt_tmp == 'x')
		str = x_to_string(ap, 0);
	else if (*fmt_tmp == 'X')
		str = x_to_string(ap, 1);
    else if (*fmt_tmp == 'p')
        str = p_to_string(ap);
	else // エラーを返す
		return (LONG_MAX);
	str = apply_flag(str, flag);
	free(flag);
	*fmt = ++fmt_tmp;
	return (write_str(str, c_null));
}

size_t	extract_text(const char *fmt, size_t len)
{
    char *str;
	char *str_tmp;

    str = ft_calloc(len+1, sizeof(char));
	if (!str)
		return (LONG_MAX);
	str_tmp = str;
    while (len--)
        *str++ = *fmt++;
	// write(1, "here4\n", 7);
	return (write_str(str_tmp, 0));
}

int	check_len(int write_len, size_t total_len)
{
	total_len += write_len;
	if (total_len > INT_MAX)
		return (1);
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	char *p;
	size_t	total_len;
	int write_len;

	if (fmt == NULL)
		return (-1);
	total_len = 0;
	va_start(ap, fmt);
	while (*fmt != '\0')
	{
		p = (char *)fmt;
		while (*p != '%' && *p != '\0')
		    p++;
		if (p != fmt)
		{
		    write_len = extract_text(fmt, p-fmt);
			fmt = p;
		}
		else if (*p == '%')
		{
			++fmt;
		    write_len = parse(&fmt, &ap);
			
		}
	    if (write_len > INT_MAX || check_len(write_len, total_len))
			return (-1);
		total_len += write_len;
	}
	va_end(ap);
	return ((int)total_len);
}