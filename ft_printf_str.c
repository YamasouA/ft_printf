#include "ft_printf.h"

// libft
size_t	ft_strlen(const char *str)
{
	size_t	cnt;

	cnt = 0;
	while (*str++)
		cnt++;
	return (cnt);
}

// libft
int	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
	int		cnt;

    cnt = 0;
	if (s == NULL)
		return (-1);
	len = ft_strlen(s);
	while (len--)
		cnt += (int)write(fd, s++, 1);
    return (cnt);
}


int	put_str(const char *fmt, va_list ap)
{
	int	len;
	char	*s;

	s = va_arg(ap, char *);
	len = ft_putstr_fd(s, 1);
	return (len);
}
