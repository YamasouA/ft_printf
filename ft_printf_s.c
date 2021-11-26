#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	cnt;

	cnt = 0;
	while (*str++)
		cnt++;
	return (cnt);
}

int	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
	int		cnt;

    cnt = 0;
	if (s == NULL)
		return (-1);
	len = ft_strlen(s);
	while (len > INT_MAX)
	{
		write(fd, s, INT_MAX);
		s += INT_MAX;
		len -= INT_MAX;
		cnt += INT_MAX;
	}
	write(fd, s, len);
	cnt += (int)len;
    return (cnt);
}

int	put_str(va_list ap)
{
	int	len;
	char	*s;

	s = va_arg(ap, char *);
	len = ft_putstr_fd(s, 1);
	return (len);
}