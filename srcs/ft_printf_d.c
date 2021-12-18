#include "ft_printf.h"

static	int	ft_putnbr(long long n, int fd)
{
	char	s;
	int		len;

	s = '0';
	len = 0;
	if (n <= 9)
	{
		s += n;
		return ((int)write(fd, &s, 1));
	}
	else
	{
		len += ft_putnbr(n / 10, fd);
		s += n % 10;
		len += (int)write(fd, &s, 1);
		return (len);
	}
}

int	put_decimal(va_list ap)
{
	long long	n;
	int			len;

	len = 0;
	n = (long long)va_arg(ap, int);
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
		len++;
	}
	len += ft_putnbr(n, 1);
	return (len);
}
