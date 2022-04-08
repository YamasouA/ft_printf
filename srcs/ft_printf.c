#include "../includes/ft_printf.h"

int	write_fmt(const char **fmt, pflag *flag, va_list *ap)
{
	int	len;

	if (**fmt == 'c')
		len = write_c(fmt, flag, ap);
	else if (**fmt == '%')
		len = write_c(fmt, flag, ap);
	else if (**fmt == 's')
		len = write_s(flag, ap);
	else if (**fmt == 'd' || **fmt == 'i' || **fmt == 'u')
	 	len = write_diu(fmt, flag, ap);
	else if (**fmt == 'x' || **fmt == 'X')
		len = write_xX(fmt, flag, ap);
	else if (**fmt == 'p')
		len = write_p(flag, ap);
	else
		len = -1;
	return (len);
}

int	parse(const char **fmt, va_list *ap)
{
	pflag	*flag;
	int	write_len;

    flag = consume(fmt, ap);
	if (!flag)
		return (-1);
	write_len = write_fmt(fmt, flag, ap);
	(*fmt)++;
	free(flag);
	return (write_len);
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