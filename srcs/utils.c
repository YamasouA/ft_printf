#include "../includes/ft_printf.h"

int number_of_digits(long long n)
{
    int cnt;

    cnt = 0;
    if (n == 0)
        return (1);
    while (n > 0)
    {
        cnt++;
        n /= 10;
    }
    return (cnt);
}