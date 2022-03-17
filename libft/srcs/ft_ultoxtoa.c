#include "libft.h"

size_t  count_n(unsigned long u, size_t base_n)
{
    size_t cnt;

    cnt = 0;
    if (u == 0)
        return (1);
    while (u > 0)
    {
        u /= base_n;
        cnt++;
    }
    return (cnt);
}

char    *ft_ultoxtoa(unsigned long u, char *base)
{
    char    *str;
    size_t  base_n;
    size_t  cnt;

    base_n = ft_strlen(base);
    cnt = count_n(u, base_n);
    str = (char *)ft_calloc(cnt + 1, sizeof(char));
    if (str == NULL)
        return (NULL);
    while (cnt--)
    {
        str[cnt] = base[u % 16];
        u /= 16;
    }
    return (str);
}