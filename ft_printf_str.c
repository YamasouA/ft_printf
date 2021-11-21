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
size_t	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
    size_t  cnt;

    cnt = 0;
	if (s == NULL)
		return ;
	len = ft_strlen(s);
	while (len--)
    {
		write(fd, s++, 1);
        cnt++;
    }
    return (cnt);
}


int	put_str(const char *fmt, va_list ap)
{
	size_t	len;
    size_t  cnt_write;
	char	*s;

	s = va_arg(ap, char *);
	cnt_write = ft_putstr_fd(s, 1);
	len = ft_strlen(s);
    if (cnt != len)
        return (-1);
	return (len);
}
