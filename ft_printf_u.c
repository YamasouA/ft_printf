#include "ft_printf.h"

int write_udecimal(unsigned int n)
{
    char    c;
    int     len;

    c = '0';
    len = 0;
    if (n <= 9)
    {
        c += n;
        write(1, &c, 1);
        return (1);
    }
    else
    {
        len += write_udecimal(n / 10);
        c += n % 10;
        write(1, &c, 1);
        len++;
        return (len);
    }
}

int put_unsigned_decimal(va_list ap)
{
    unsigned int    n;

    n = va_arg(ap, unsigned int);
    write_udecimal(n);

    return 0;
}
