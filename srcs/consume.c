#include "../includes/ft_printf.h"

pflag	*init_flag()
{
	pflag	*flag;

	flag = ft_calloc(1, sizeof(pflag));
	if (!flag)
		return (NULL);
	flag->flag = 0;
	flag->c = '\0';
	flag->field_width = 0;
	flag->precision = 0;
	return (flag);
}


void	flag_priority(pflag *flag)
{
	if ((flag->flag & FLAG_MINUS) && (flag->flag & FLAG_ZERO))
		flag->flag &= ~FLAG_ZERO;
	if ((flag->flag & FLAG_PLUS) && (flag->flag & FLAG_SPACE))
		flag->flag &= ~FLAG_SPACE;
}

void	flag_consume(const char **fmt, pflag *flag)
{
    while (**fmt != '\0' && ft_strchr("0-#+ ", **fmt))
	{
		if (**fmt == '-')
			flag->flag |= FLAG_MINUS;
		else if (**fmt == '0')
			flag->flag |= FLAG_ZERO;
		else if (**fmt == ' ')
			flag->flag |= FLAG_SPACE;
		else if (**fmt == '#')
			flag->flag |= FLAG_SHARP;
		else if (**fmt == '+')
			flag->flag |= FLAG_PLUS;
		(*fmt)++;
	}
	flag_priority(flag);
}

void	width_consume(const char **fmt, pflag *flag, va_list *ap)
{
	long long width;

	if (**fmt == '*')
	{
		width = va_arg(*ap, int);
		if (width < 0)
        {
            flag->flag |= FLAG_MINUS;
		    width *= -1;
        }
		flag->field_width = width;
		(*fmt)++;
	}
	else if (ft_isdigit(**fmt))
	{
        width = ft_atol(*fmt);
        (*fmt) += number_of_digits(width);
        flag->field_width = width;
	}
}

void	precision_consume(const char **fmt, pflag *flag, va_list *ap)
{
	int	precision;

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
			flag->precision = ft_atol(*fmt);
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
	flag_consume(fmt, flag);
	width_consume(fmt, flag, ap);
	precision_consume(fmt, flag, ap);
	return (flag);
}
