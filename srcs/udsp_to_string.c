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
    int cnt;
    char *s;

    cnt = 0;
    ul = (unsigned long)va_arg(ap, void *);
    return print(ft_ultoa(ul), flag);
}

char *x_to_string(va_list ap, int type, pflag *flag)
{

}