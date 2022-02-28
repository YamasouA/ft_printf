#include "ft_printf.h"

char *u_to_string(va_list ap, pflag *flag)
{
    unsigned int    n;

    n = va_arg(ap, unsigned int);
    return print(ft_utoa(n), flag);
}

char *d_to_string(va_list ap, pflag *flag)
{
    int n;

    n = va_arg(ap, int);
    return print(ft_itoa(n), flag);
}

char *s_to_string(va_list ap, pflag *flag)
{
    char *s;

    s = va_arg(ap, char *);
    if (!s)
        *s = "(null)";
    return print(ft_strdup(s), flag);
}

char *p_to_string(va_list ap, pflag *flag)
{
    unsigned long ul;

    ul = (unsigned long)va_arg(ap, void *);
    return print(ft_ultoa(ul, "0123456789"), flag);
}

char *x_to_string(va_list ap, int type, pflag *flag)
{
    char *base[2][16] = {"0123456789abcdef", "0123456789ABCDEF"};
    char *b;

    b = base[type];

}