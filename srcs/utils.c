#include "../includes/ft_printf.h"

int number_of_digits(int n)
{
    int cnt;

    cnt = 0;
    while (n > 0)
    {
        cnt++;
        n /= 10;
    }
    return (cnt);
}