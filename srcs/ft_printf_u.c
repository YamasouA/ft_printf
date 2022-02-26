#include "ft_printf.h"

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
        *s = "(null)";
    return ft_strdup(s);
}

char *p_to_string(va_list ap)
{
    unsigned long long ll;
    int cnt;
    char *s;

    cnt = 0;
    ll = va_arg(ap, long long);
    if (ll < 0)
        ll = ULONG_MAX + ll + 1;
    s = 
    return s;
}

char *x_to_string(va_list ap, bool x)
{

}