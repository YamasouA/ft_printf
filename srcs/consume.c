#include "../includes/ft_printf.h"

pflag	*init_flag()
{
	pflag	*flag;

	flag = ft_calloc(1, sizeof(pflag));
	if (!flag)
		return (NULL);
	flag->is_alignleft = false;
	flag->is_padding = false;
	flag->is_precision = false;
	flag->is_specifier = false;
	flag->is_alignspace = false;
	flag->is_assign = false;
	flag->convert = NULL;
	flag->field_width = 0;
	flag->precision = 0;
	return (flag);
}

int	check_priority(pflag *flag, const char *fmt)
{
	// 元々の方が優先度高い -> 0
	// 共存できる -> 1
	// 新しい方が優先度高い -> 1
	if (flag->is_alignleft && *fmt == '0')
		return (0);
	else if (flag->is_assign && *fmt == ' ')
		return (0);
	// else if (flag->is_precision && (*fmt == '0' || *fmt == '-'))
	// 	return (0);
		// return (0);
	return (1);
}

void	change_flag_status(pflag *flag, const char *fmt)
{
	// 古いフラグを消す
	if (flag->is_padding && *fmt == '-')
		flag->is_padding = false;
	// else if (flag->is_precision && *fmt == '-')
	// 	flag->is_precision = false;
}

size_t	consume_n(char **fmt)
{
	int base;
	size_t n;
	char	*c;

	c = (char *)*fmt;
	base = 1;
	n = 0;
	if (*c == '-')
		return (n);
	while (*c != '\0')
	{
		if (ft_isdigit(*c))
		{
			n = (*c - '0') + n * base;
			if (base == 1)
				base *= 10;
		}
		else
			break;
		c++;
	}
	*fmt = --c; // consume flagでfmtを一つ進めるため
	return (n);
}

int	flag_priority(pflag *flag, char **fmt)
{
	int	ret;
	char	*fmt_tmp;

	fmt_tmp = *fmt;
	// printf("here: %c\n", *fmt_tmp);
	ret = check_priority(flag, fmt_tmp);
	// printf("ret: %d\n", ret);
	if (ret)
	{
		change_flag_status(flag, fmt_tmp);
		return (ret);
	}
	// if (flag->is_padding && *fmt_tmp == '-')
	// 	flag->is_padding = false;
	// else if (flag->is_alignspace && *fmt_tmp == '+')
	// 	flag->is_alignspace = false;
	// else if (flag->is)
	// change_flag_status(flag, fmt_tmp);
	fmt_tmp++;
	consume_n(&fmt_tmp);
	*fmt = ++fmt_tmp;
	// printf("%c\n", *fmt_tmp);
	return (ret);
}

int	flag_consume(char **fmt, pflag *flag)
{
	char *fmt_tmp;

	fmt_tmp = *fmt;
	if (!ft_strchr("0-.", *fmt_tmp))
	{
		flag->is_alignspace = 1;
		fmt_tmp++;
	}
	else
	{
		// while (*fmt_tmp != '\0')
		// {
			if (flag_priority(flag, &fmt_tmp))
			{
				// if (ft_isdigit(*fmt_tmp) && fmt_tmp[-1] == '.')
					// flag->precision = consume_n(&fmt_tmp);
				// else if (ft_isdigit(*fmt_tmp) && (fmt_tmp[-1] == '0' || fmt_tmp[-1] == '-'))
					// flag->field_width = consume_n(&fmt_tmp);
				// else if (*fmt_tmp == '-')
				if (*fmt_tmp == '-')
					flag->is_alignleft = 1;
				else if (*fmt_tmp == '0')
					flag->is_padding = 1;
				else if (*fmt_tmp == ' ')
					flag->is_alignspace = 1;
				else if (*fmt_tmp == '.')
					flag->is_precision = 1;
				else if (*fmt_tmp == '#')
					flag->is_specifier = 1;
				else if (*fmt_tmp == '+')
					flag->is_specifier = 1;
				// else
				// 	break;
				fmt_tmp++;
			}
		// }
		*fmt = fmt_tmp;
	}
	return (1);
}

// void	width_consume(const char **fmt, pflag *flag)
void	width_consume()
{

	// flag->field_width = consume_n()
	return ;
}

void	precision_consume()
{
	return ;
}

// void	consume_width()

pflag   *consume(const char **fmt)
{
	char	*fmt_tmp;
	pflag	*flag;
	int	ret;

	flag = init_flag();
	if (!flag)
		return (NULL);
	fmt_tmp = (char *)*fmt;
	// printf("%c\n", *fmt_tmp);
	// printf("%s\n", ft_strchr("cspdiuxX%", 'k'));
    while (*fmt_tmp != '\0' && !ft_strchr("cspdiuxX%", *fmt_tmp))
	{
		ret = flag_consume(&fmt_tmp, flag);
		if (ret)
			flag->field_width = consume_n(&fmt_tmp);
		// flag = precision_consume();
		fmt_tmp++;
	}
	*fmt = fmt_tmp;
	return (flag);
}