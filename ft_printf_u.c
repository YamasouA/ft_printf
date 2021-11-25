#include "ft_printf.h"

static int count_nbr(unsigned int nbr)
{
    int len;

    len = 0;
    while (nbr > 0)
    {
        len++;
        nbr /= 10;
    }
    return (len);
}

void write_udecimal(unsigned int n)
{
    char    c;

    c = '0';
    if (n <= 9)
    {
        c += n;
        write(1, &c, 1);
    }
    else
    {
        write_udecimal(n / 10);
        c += n % 10;
        write(1, &c, 1);
    }
}

int put_unsigned_decimal(const char *fmt, va_list ap)
{
    unsigned int    n;

    n = va_arg(ap, unsigned int);
    write_udecimal(n);

    return 0;
}
