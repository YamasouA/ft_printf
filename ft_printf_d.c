#include "ft_printf.h"

int	count_nbr(int n)
{
	int	len;

	len = 0;
	if (n == INT_MIN)
		return (11);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static	void	ft_putnbr(long n, int fd)
{
	char	s;

	s = '0';
	if (n <= 9)
	{
		s += n;
		write(fd, &s, 1);
	}
	else
	{
		ft_putnbr(n / 10, fd);
		s += n % 10;
		write(fd, &s, 1);
	}
}

// libft
void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = (long)n;
	if (ln < 0)
	{
		ln *= -1;
		write(fd, "-", 1);
	}
	ft_putnbr(ln, fd);
}

ssize_t	put_decimal(const char *fmt, va_list ap)
{
	int	n;

	n = va_arg(ap, int);
	ft_putnbr_fd(n, 1);
	return (count_nbr(n));
}