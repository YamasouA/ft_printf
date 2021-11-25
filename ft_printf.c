#include "ft_printf.h"


// ssize_tじゃない方が良い
int	parse(const char *fmt, va_list ap)
{
	if (*fmt == 'c')
		return (put_chr(fmt, ap));
	else if (*fmt == 's') // 実装どうしよう
		return (put_str(fmt, ap));
	else if (*fmt == 'd' || *fmt == 'i')
	 	return (put_decimal(fmt, ap));
	else if (*fmt == 'u')
	        return (put_unsigned_decimal(fmt, ap));
	else if (*fmt == 'x')
		return (put_hex(fmt, ap, 0));
	else if (*fmt == 'X')
		return (put_hex(fmt, ap, 1));
    else if (*fmt == 'p')
        return (put_hex(fmt, ap, 2));
	else
	{
		write(1, "%", 1);
		return (1);
	}
}

int ft_printf(const char *fmt, ...)
{
	int	len;
	va_list	ap;

	len = 0;
	if (fmt == NULL)
		return (-1);
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			len += parse(fmt++, ap); // % dcxXなどを見てapから書き出す
		}
		else
			len += write(1, fmt++, 1); // 残りの文字列はこっちで処理する
	}
	va_end(ap);
	return (len);
}
