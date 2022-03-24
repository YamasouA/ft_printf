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
	pflag	*flag;
	char	*str;
	int		c_null;

	c_null = 0;
    flag = consume(fmt, ap);
	// printf("fmt: %s\n", *fmt);
	// flag = flag_priority(flag);
	if (!flag)
		return (LONG_MAX);
	if (**fmt == 'c')
		str = c_to_string(va_arg(*ap, int), &c_null);
	else if (**fmt == '%')
		str = c_to_string('%', &c_null);
	else if (**fmt == 's')
		str = s_to_string(ap);
	else if (**fmt == 'd' || **fmt == 'i')
	 	str = d_to_string(ap);
	else if (**fmt == 'u')
	    str = u_to_string(ap);
	else if (**fmt == 'x')
		str = x_to_string(ap, 0);
	else if (**fmt == 'X')
		str = x_to_string(ap, 1);
    else if (**fmt == 'p')
        str = p_to_string(ap);
	else // エラーを返す
		return (LONG_MAX);
	str = apply_flag(str, flag);
	free(flag);
	(*fmt)++;
	return (write_str(str, c_null));
}

int	check_len(int n, int write_len)
{
	size_t	total_len;

	total_len = write_len + n;
	if (n < 0 || total_len > INT_MAX)
		return (-1);
	return ((int)total_len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int	write_len;
	size_t	len;

	if (fmt == NULL)
		return (-1);
	write_len = 0;
	va_start(ap, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			len = parse(&fmt, &ap);
	    	if (len > INT_MAX)
				write_len = -1;
			write_len = check_len(len, write_len);
		}
		else
			write_len = check_len(write(1, fmt++, 1), write_len);
		if (write_len == -1)
			break;
	}
	va_end(ap);
	return (write_len);
}