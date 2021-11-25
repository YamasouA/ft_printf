#include "ft_printf.h"

static	int	ft_putnbr(long n, int fd)
{
	char	s;
	int		len;

	s = '0';
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

// libft
int	ft_putnbr_fd(int n, int fd)
{
	long long	ln;
	int			len;

	ln = (long long)n;
	if (ln < 0)
	{
		ln *= -1;
		write(fd, "-", 1);
		len++;
	}
	len += ft_putnbr(ln, fd);
	return (len);
}

ssize_t	put_decimal(const char *fmt, va_list ap)
{
	int	n;
	int	len;

	n = va_arg(ap, int);
	len = ft_putnbr_fd(n, 1);
	return (len);
}