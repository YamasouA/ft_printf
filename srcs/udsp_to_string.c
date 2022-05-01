#include "../includes/ft_printf.h"

char *u_to_string(va_list *ap)
{
    unsigned int    n;

    n = va_arg(*ap, unsigned int);
    return (ft_utoa(n));
}

char *d_to_string(va_list *ap)
{
    int n;
    
    n = va_arg(*ap, int);
    return (ft_itoa(n));
}

char *p_to_string(va_list *ap)
{
    unsigned long long	ul;
	//void	*ul;
    char    *str;
    char    *ret;

    ul = (unsigned long long)va_arg(*ap, void *);
    str = ft_ultoxtoa(ul, "0123456789abcdef");
    ret = ft_strjoin("0x", str);
    free(str);
    return (ret);
}

char *x_to_string(va_list *ap, char c)
{
    char base[2][17] = {"0123456789abcdef", "0123456789ABCDEF"};
    char *b;
    unsigned int u;
    int type;

    if (c == 'x')
        type = 0;
    else
        type = 1;
    b = base[type];
    u = va_arg(*ap, unsigned int);

    return (ft_ultoxtoa(u, b));

}
