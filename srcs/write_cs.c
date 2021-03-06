#include "../includes/ft_printf.h"

int	write_flag_c(char c, int width)
{
	int	cnt;

	cnt = 0;
	if (width < 0)
		return (cnt);
	while (width--)
	{
		write(1, &c, 1);
		cnt++;
	}
	return (cnt);
}

static int	write_flag_head(pflag *flag, int width_len)
{
	int	write_len;

	write_len = 0;
	if (width_len < 0)
		return (0);
	if (flag->flag & FLAG_SPACE || flag->flag == 0 || flag->flag & FLAG_PLUS)
		write_len += write_flag_c(' ', width_len);
	if (flag->flag & FLAG_ZERO)
		write_len += write_flag_c('0', width_len);
	return (write_len);
}

static int	write_flag_tail(pflag *flag, size_t	width_len)
{
	int	write_len;

	write_len = 0;
	if (flag->flag & FLAG_MINUS)
		write_len += write_flag_c(' ', width_len);
	return (write_len);
}

int	write_c(const char **fmt, pflag *flag, va_list *ap)
{
	int	write_len;
	unsigned char	c;

	c = '%';
	if (**fmt != '%')
		c = (unsigned char)va_arg(*ap, int);
	write_len = 0;
	if (flag->field_width > INT_MAX)
		return (-1);
	if (flag->field_width > 0)
		write_len += write_flag_head(flag, flag->field_width - 1);
	write_len += write(1, &c, 1);
	if (flag->field_width > 0)
		write_len += write_flag_tail(flag, flag->field_width - 1);
	return (write_len);
}

int	write_s(pflag *flag, va_list *ap)
{
	size_t	str_len;
	size_t	width_len;
	int		write_len;
	char *str;

	str = va_arg(*ap, char *);
	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	width_len = 0;
	write_len = 0;
	if (flag->is_precision && str_len > flag->precision)
		str_len = flag->precision;
	if (flag->field_width > str_len)
		width_len = flag->field_width - str_len;
	if (str_len > INT_MAX || flag->field_width > INT_MAX)
		return (-1);
	write_len += write_flag_head(flag, width_len);
	write_len += write(1, str, str_len);
	write_len += write_flag_tail(flag, width_len);
	return (write_len);
}
