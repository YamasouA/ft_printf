#include "../includes/ft_printf.h"
#include <stdio.h>
char	*flag_char(char *str1, char c, size_t n, int flag)
{
	char *str;
	size_t	len;
	
	// printf("%zu: %zu\n", n, ft_strlen(str1));
	if (n <= ft_strlen(str1))
		return ("");
	len = n - ft_strlen(str1);
	if (flag)
		if (*str1 == '-')
			len++;
	// printf("here: %zu\n", len);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (len--)
		str[len] = c;
	// printf("flag_char: %s\n", str);
	// write(1, "here\n", 5);
	return (str);
}

char	*ft_insert(char *str, char *str2, size_t n)
{
	size_t	str_len;
	size_t	str2_len;
	size_t	i;
	char *str_join;

	if (!str || !str2)
		return (NULL);
	str_len = ft_strlen(str);
	str2_len = ft_strlen(str2);
	str_join = (char *)ft_calloc(str_len + str2_len + 1, sizeof(char));
	if (!str_join)
		return (NULL);
	i = 0;
	while (i <= str_len)
	{
		if (i == n)
		{
			str_join[i++] = *str2++;
			str2_len--;
		}
		str_join[i++] = *str++;
	}
	i = 1;
	while (i <= str2_len)
		str_join[str_len + i++] = *str2++;
	// printf("str: %s\n", str_join);
	return (str_join);
}

char	*apply_width(char *str1, char *str2, int insert)
{
	char	*str;
	int		flag;

	// printf("str1: %s\n", str1);
	// printf("str2: %s\n", str2);
	if (!str1 || !str2)
		return (NULL);
	
	flag = *str2 == '-';
	// str = (char *)ft_calloc(ft_strlen(str1) + ft_strlen(str2) + 1, sizeof(char));
	insert--; // ここはなおせ
	if (flag)
		str = ft_insert(str1, str2, 0);
	else
		str = ft_strjoin(str1, str2);
	// free(str1);
	// free(str2);
	// printf("s is: %s\n", str);
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
	return (str);
}

char	*apply_flag(char *str, pflag *flag)
{
	char *str2;

	// printf("%zu\n", flag->precision);
	// printf("%zu\n", flag->field_width);
	str2 = str;
	if (flag->is_precision) // '.'
	{	// 文字列の先頭が'-'の場合は'-'をfield_widthにカウントしない
		str = apply_width(flag_char(str, '0', flag->precision, 1), str, 1);
		// printf("here: %send\n", str);
	}
	if (flag->is_alignleft) // '-'
	{
		str = apply_width(str, flag_char(str, ' ', flag->field_width, 0), 0);
		// printf("there2: %send\n", str);
	}	
	if (flag->is_padding) // '0'
	{	// str = apply_padding(str, flag); // strの先頭が-かどうかで処理が変わる
		// 文字列の先頭が'-'の場合は'-'をfield_widthにカウントする
		str = apply_width(flag_char(str, '0', flag->field_width, 0), str, 1);
		// printf("there: %send\n", str);
	}
	// if (flag->is_specifier) // '#'
	// 	str = apply_convert(str, flag);;
	// if (flag->is_alignspace) // ' '
	// 	if (*str != '-')
	// 		str = ft_strjoin(" ", str);
	// if (flag->is_assign) // +
	// 	if (*str != '-')
	// 		str = ft_strjoin("+", str);
	

	if (!str)
		return (str2);
	return (str);
}

size_t	consume_n(const char **fmt)
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
		// printf("aaa\n");
		c++;
	}
	// printf("n::::%zu\n", n);
	// write(1, fmt, 1);
	// write(1, "\n", 1);
	*fmt = --c; // consume flagでfmtを一つ進めるため
	return (n);
}

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

int	flag_priority(pflag *flag, const char **fmt)
{
	int	ret;
	const char	*fmt_tmp;

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

pflag	*flag_consume(const char **fmt)
{
	pflag	*flag;
	const char *fmt_tmp;

	flag = init_flag();
	fmt_tmp = *fmt;
	if (!flag)
		return (NULL);
	while (*fmt_tmp != '\0')
	{
		if (flag_priority(flag, &fmt_tmp))
		{
			if (ft_isdigit(*fmt_tmp) && fmt_tmp[-1] == '.')
				flag->precision = consume_n(&fmt_tmp);
			else if (ft_isdigit(*fmt_tmp) && (fmt_tmp[-1] == '0' || fmt_tmp[-1] == '-'))
				flag->field_width = consume_n(&fmt_tmp);
			else if (*fmt_tmp == '-')
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
			else
				break;
			fmt_tmp++;
		}
		// printf("n: %zu\n", flag->field_width);
	}
	*fmt = fmt_tmp;
	return (flag);
}

size_t	write_str(char *str)
{
	size_t	len;

	if (!str)
		return (1);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

size_t write_c(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

size_t	parse(const char **fmt, va_list *ap)
{
	pflag *flag;
	char	*str;
	const char	*fmt_tmp;

	fmt_tmp = *fmt;
    flag = flag_consume(&fmt_tmp);
	// flag = flag_priority(flag);
	if (!flag)
		return (LONG_MAX);
	if (*fmt_tmp == 'c')
		str = c_to_string(va_arg(*ap, int));
	else if (*fmt_tmp == '%')
		str = c_to_string('%');
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
	// printf("parse: %s\n", str);
	// flag_clear(flag);
	*fmt = ++fmt_tmp;
	return (write_str(str));
}

size_t	extract_text(const char *fmt, size_t len)
{
    char *str;
	char *str_tmp;

    str = ft_calloc(len+1, sizeof(char));
	str_tmp = str;
    while (len--)
        *str++ = *fmt++;
	return (write_str(str_tmp));
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