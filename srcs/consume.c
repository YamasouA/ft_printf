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

// int	check_priority(pflag *flag, const char *fmt)
// {
// 	// 元々の方が優先度高い -> 0
// 	// 共存できる -> 1
// 	// 新しい方が優先度高い -> 1
// 	if ((flag->fl_type == FLAG_MINUS) && *fmt == '0')
// 		return (0);
// 	else if ((flag->fl_type == FLAG_PLUS) && *fmt == ' ')
// 		return (0);
// 	// else if (flag->is_precision && (*fmt == '0' || *fmt == '-'))
// 	// 	return (0);
// 		// return (0);
// 	return (1);
// }

// void	change_flag_status(pflag *flag, const char *fmt)
// {
// 	// 古いフラグを消す
// 	if ((flag->fl_type == FLAG_ZERO) && *fmt == '-')
// 		flag->fl_type = FLAG_NONE;
// 	// else if (flag->is_precision && *fmt == '-')
// 	// 	flag->is_precision = false;
// }

// size_t	consume_n(const char **fmt)
// {
// 	int base;
// 	size_t n;
// 	char	*c;

// 	c = (char *)*fmt;
// 	base = 1;
// 	n = 0;
// 	if (*c == '-')
// 		return (n);
// 	while (*c != '\0')
// 	{
// 		if (ft_isdigit(*c))
// 		{
// 			n = (*c - '0') + n * base;
// 			if (base == 1)
// 				base *= 10;
// 		}
// 		else
// 			break;
// 		c++;
// 	}
// 	*fmt = --c; // consume flagでfmtを一つ進めるため
// 	return (n);
// }

int	flag_priority(pflag *flag, const char **fmt)
{
	// int	ret;
	// char	*fmt_tmp;

	// printf("here: %c\n", *fmt_tmp);
	// ret = check_priority(flag, *fmt);
	if ((flag->fl_type == FLAG_MINUS) && **fmt == '0')
		return (0);
	else if ((flag->fl_type == FLAG_PLUS) && **fmt == ' ')
		return (0);
	// else if (flag->is_precision && (*fmt == '0' || *fmt == '-'))
	// 	return (0);
		// return (0);
	return (1);
	// printf("ret: %d\n", ret);
	// if (ret)
	// {
	// 	change_flag_status(flag, *fmt);
	// 	return (ret);
	// }
	// if (flag->is_padding && *fmt_tmp == '-')
	// 	flag->is_padding = false;
	// else if (flag->is_alignspace && *fmt_tmp == '+')
	// 	flag->is_alignspace = false;
	// else if (flag->is)
	// change_flag_status(flag, fmt_tmp);
	// (*fmt)++;
	// consume_n(fmt);
	// *fmt = ++fmt_tmp;
	// printf("%c\n", *fmt_tmp);
	// return (ret);
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
			// else if (**fmt == '.')
			// 	flag->fl_type = FLAG_DOT;
			else if (**fmt == '#')
				flag->fl_type = FLAG_SHARP;
			else if (**fmt == '+')
				flag->fl_type = FLAG_PLUS;
		}
		(*fmt)++;
	}
}

// void	width_consume(const char **fmt, pflag *flag)
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
		// width = ft_atoi(*fmt);
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
		// printf("fmt2.5: %s\n", *fmt);
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
			// printf("hello\n");
			flag->precision = ft_atoi(*fmt);
			*fmt += number_of_digits(flag->precision);
		}
	}
}

// void	consume_width()

pflag   *consume(const char **fmt, va_list *ap)
{
	pflag	*flag;

	flag = init_flag();
	if (!flag)
		return (NULL);
	// printf("%c\n", *fmt_tmp);
	// printf("%s\n", ft_strchr("cspdiuxX%", 'k'));
	while (**fmt != '\0' && !ft_strchr("%csdiuxXp", **fmt))
	{
		flag_consume(fmt, flag);
		// printf("fmt1: %s\n", *fmt);
		width_consume(fmt, flag, ap);
		// printf("fmt2: %s\n", *fmt);
		precision_consume(fmt, flag, ap);
		// printf("fmt3: %s\n", *fmt);
	}
	// flag = precision_consume();
	// fmt_tmp++;
	return (flag);
}