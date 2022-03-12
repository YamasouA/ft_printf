#include "../includes/ft_printf.h"

char *u_to_string(va_list ap)
{
    unsigned int    n;

    n = va_arg(ap, unsigned int);
    return ft_utoa(n);
}

char *d_to_string(va_list ap)
{
    int n;

    n = va_arg(ap, int);
    return ft_itoa(n);
}

char *s_to_string(va_list ap)
{
    char *s;

    s = va_arg(ap, char *);
    if (!s)
        s = "(null)";
    return ft_strdup(s);
}

char *p_to_string(va_list ap)
{
    unsigned long ul;

    ul = (unsigned long)va_arg(ap, void *);
    // return ft_ultoa(ul, "0123456789abcdef");
    return ft_ultoa(ul);
}

char *x_to_string(va_list ap, int type)
{
    char base[2][16] = {"0123456789abcdef", "0123456789ABCDEF"};
    char *b;
    long long l;

    b = base[type];
    l = va_arg(ap, long long);

    return ft_ltoa(l);

}