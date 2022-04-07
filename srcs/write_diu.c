#include "../includes/ft_printf.h"

static int	write_flag_head(pflag *flag, size_t	str_len, int n,char *str)
{
	int	write_len;
    size_t total_str;
    int width_len;

	write_len = 0;
    total_str = str_len;
    if (flag->precision > str_len)
        total_str = flag->precision;
    width_len = flag->field_width - total_str - n;
	if (flag->fl_type == FLAG_PLUS && n == 0 && flag->c == 'd')
		width_len--;
	if (flag->fl_type == FLAG_SPACE || flag->fl_type == FLAG_NONE || flag->fl_type == FLAG_PLUS)
		write_len += write_flag_c(' ', width_len);
	if (flag->fl_type == FLAG_PLUS && n == 0 && flag->c == 'd')
		write_len += write(1, "+", 1);
    write_len += write(1, str, n);
	if (flag->fl_type == FLAG_ZERO)
		write_len += write_flag_c('0', width_len);
    if (total_str > str_len)
        write_len += write_flag_c('0', total_str - str_len);
	return (write_len);
}

static int	write_flag_tail(pflag *flag, size_t	str_len, int n)
{
	int	write_len;
	int	width_len;
	size_t	total_str;

	write_len = 0;
	total_str = str_len;
    if (flag->precision > str_len)
        total_str = flag->precision;
    width_len = flag->field_width - total_str - n;
	if (flag->fl_type == FLAG_MINUS)
		write_len += write_flag_c(' ', width_len);
	return (write_len);
}

int	write_diu(const char **fmt, pflag *flag, va_list *ap)
{
	char *str;
	int	write_len;
	size_t	str_len;
	int	is_sign;

	write_len = 0;
	if (**fmt == 'u')
		str = u_to_string(ap);
	else
	{
		str = d_to_string(ap);
		flag->c = 'd';
	}
	is_sign = (*str == '-');
	str_len = ft_strlen(str) - is_sign;
	write_len += write_flag_head(flag, str_len, is_sign, str);
	if (!(!ft_strncmp(str, "0", str_len) && flag->precision == 0 && flag->is_precision))
		write_len += write(1, str + is_sign, str_len);
	write_len += write_flag_tail(flag, str_len, is_sign);
	free(str);
	return (write_len);
}

int	write_xX(const char **fmt, pflag *flag, va_list *ap)
{
	char	*str;
	int		write_len;
	size_t	str_len;

	write_len = 0;
	str = x_to_string(ap, **fmt == 'x' ? 0 : 1);
	str_len = ft_strlen(str);
	write_len += write_flag_head(flag, str_len, 0, str);
	if (!(!ft_strncmp(str, "0", str_len) && flag->precision == 0 && flag->is_precision))
		write_len += write(1, str, str_len);
	write_len += write_flag_tail(flag, str_len, 0);
	free(str);
	return (write_len);
}

int	write_p(pflag *flag, va_list *ap)
{
	char	*str;
	int		write_len;
	size_t	str_len;

	write_len = 0;
	str = p_to_string(ap);
	str_len = ft_strlen(str) - 2;
    write_len += write_flag_head(flag, str_len, 2, str);
	str += 2;
	if (!(!ft_strncmp(str, "0", str_len) && flag->precision == 0 && flag->is_precision))
		write_len += write(1, str, str_len);
	write_len += write_flag_tail(flag, str_len, 2);
	free(str - 2);
	return (write_len);
}