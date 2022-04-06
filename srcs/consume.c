#include "../includes/ft_printf.h"

pflag	*init_flag()
{
	pflag	*flag;

	flag = ft_calloc(1, sizeof(pflag));
	if (!flag)
		return (NULL);
	flag->fl_type = FLAG_NONE;
	flag->convert = NULL;
	flag->field_width = 0;
	flag->precision = 0;
	return (flag);
}


int	flag_priority(pflag *flag, const char **fmt)
{
	if ((flag->fl_type == FLAG_MINUS) && **fmt == '0')
		return (0);
	else if ((flag->fl_type == FLAG_PLUS) && **fmt == ' ')
		return (0);
	return (1);
}

void	flag_consume(const char **fmt, pflag *flag)
{
	while (**fmt != '\0' && ft_strchr("0-#+ ", **fmt))
	{
		if (flag_priority(flag, fmt))
		{
			if (**fmt == '-')
				flag->fl_type = FLAG_MINUS;
			else if (**fmt == '0')
				flag->fl_type = FLAG_ZERO;
			else if (**fmt == ' ')
				flag->fl_type = FLAG_SPACE;
			else if (**fmt == '#')
				flag->fl_type = FLAG_SHARP;
			else if (**fmt == '+')
				flag->fl_type = FLAG_PLUS;
		}
		(*fmt)++;
	}
}

void	width_consume(const char **fmt, pflag *flag, va_list *ap)
{
	size_t	width;

	if (**fmt == '*')
	{
		width = va_arg(*ap, int);
		if (width < 0)
		{

		}
		flag->field_width = width;
		(*fmt)++;
	}
	else if (ft_isdigit(**fmt))
	{
		flag->field_width = ft_atoi(*fmt);
		(*fmt) += number_of_digits(flag->field_width);
	}
}

void	precision_consume(const char **fmt, pflag *flag, va_list *ap)
{
	size_t	precision;

	if (**fmt == '.')
	{
		flag->is_precision = 1;
		(*fmt)++;
		if (**fmt == '*')
		{
			precision = va_arg(*ap, int);
			if (precision >= 0)
				flag->precision = precision;
			(*fmt)++;
		}
		else if (**fmt == '-')
			return ;
		else if (ft_isdigit(**fmt))
		{
			flag->precision = ft_atoi(*fmt);
			(*fmt) += number_of_digits(flag->precision);
		}
	}
}

pflag   *consume(const char **fmt, va_list *ap)
{
	pflag	*flag;

	flag = init_flag();
	if (!flag)
		return (NULL);
	while (**fmt != '\0' && !ft_strchr("%csdiuxXp", **fmt))
	{
		flag_consume(fmt, flag);
		width_consume(fmt, flag, ap);
		precision_consume(fmt, flag, ap);
	}
	return (flag);
}