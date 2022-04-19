#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "./includes/ft_printf.h"

void check(int i, int j)
{
    if (i != j)
    {
        printf("printf: %d\n", i);
        printf("ft_printf: %d\n", j);
        printf("error!!\n");
        exit(0);
    }
    printf("\n");
}

void d_check(int d)
{
    int i, j;
    i = printf("[%d]\n", d);
    j = ft_printf("[%d]\n", d);
    check(i, j);
}

void i_check(int d)
{
    int i, j;
    i = printf("[%i]\n", d);
    j = ft_printf("[%i]\n", d);
    check(i, j);
}

void c_check(char c)
{
    int i, j;
    i = printf("[%c]\n", c);
    j = ft_printf("[%c]\n", c);
    check(i, j);
}

void s_check(char *s)
{
    int i, j;
    i = printf("[%s]\n", s);
    j = ft_printf("[%s]\n", s);
    check(i, j);
}

void u_check(unsigned int u)
{
    int i, j;
    i = printf("[%u]\n", u);
    j = ft_printf("[%u]\n", u);
    check(i, j);
}

void p_check(long long p)
{
    int i, j;
    i = printf("[%p]\n", p);
    j = ft_printf("[%p]\n", p);
    check(i, j);
}

void x_check(long long x)
{
    int i, j;
    i = printf("[%x]\n", x);
    j = ft_printf("[%x]\n", x);
    check(i, j);
}

void X_check(long long x)
{
    int i, j;
    i = printf("[%X]\n", x);
    j = ft_printf("[%X]\n", x);
    check(i, j);
}

int main()
{
    printf("=============== text only =============\n");
    int k = printf("[Hello World !!]\n");
    int l = ft_printf("[Hello World !!]\n");
    check(k, l);
    k = printf("[\tabcd]\n");
    l = ft_printf("[\tabcd]\n");
    check(k, l);

    printf("\n=============== %%d ===============\n");
    d_check(1234);
    d_check(-1234);
    d_check(INT_MAX);
    d_check(INT_MIN);
    d_check(0);

    printf("\n=============== %%i ===============\n");
    i_check(1234);
    i_check(-1234);
    i_check(INT_MAX);
    i_check(INT_MIN);
    i_check(0);

    printf("\n=============== %%s ===============\n");
    s_check("abcd");
    s_check("\n");
    s_check("");
    s_check("Hello World");

    printf("\n=============== %%c ===============\n");
    c_check('a');
    c_check('\n');
    c_check(' ');
    c_check(100);

    ft_printf("\n=============== %%x ===============\n");
    x_check(255);
    x_check(-255);
    x_check(16);
    x_check(-16);
    x_check(0);
    x_check(INT_MAX);
    x_check(INT_MIN);
    x_check(LONG_MAX);
    x_check(LONG_MIN);

    ft_printf("\n=============== %%X ===============\n");
    X_check(255);
    X_check(-255);
    X_check(16);
    X_check(-16);
    X_check(0);
    X_check(INT_MAX);
    X_check(INT_MIN);
    X_check(LONG_MAX);
    X_check(LONG_MIN);

    printf("\n=============== %%u ===============\n");
    u_check(255);
    u_check(-255);
    u_check(0);
    u_check(UINT_MAX);
    u_check(INT_MAX);
    u_check(INT_MIN);
    u_check(LONG_MAX);
    u_check(LONG_MIN);

    printf("\n=============== %%p ===============\n");
    p_check(INT_MIN);
    p_check(INT_MAX);
    p_check(0);
    p_check(LONG_MIN);
    p_check(LONG_MAX);
    p_check(UINT_MAX);
    p_check(ULLONG_MAX);

    printf("\n=============== NULL case ============\n");
    d_check(NULL);
    i_check(NULL);
    u_check(NULL);
    c_check(NULL);
    s_check(NULL);
    x_check(NULL);
    X_check(NULL);
    p_check(NULL);

    int x = printf("[%c %c %c]\n", '0', 0, '1');
    int y = ft_printf("[%c %c %c]\n", '0', 0, '1');
    check(x, y);

    printf("\n=============== multiple format ===============\n");
    int i = printf("[format %c %s %% %d %i %u %x %X %p]\n", 'a', "HELLO", INT_MIN, INT_MAX, UINT_MAX, UINT_MAX, INT_MIN, ULONG_MAX);
    int j = ft_printf("[format %c %s %% %d %i %u %x %X %p]\n", 'a', "HELLO", INT_MIN, INT_MAX, UINT_MAX, UINT_MAX, INT_MIN, ULONG_MAX);
    check(i, j);

    i = printf("[%s %s %d %p %p %x]\n", "Hello", "world", INT_MAX, LONG_MIN, 0, LONG_MAX);
    j = ft_printf("[%s %s %d %p %p %x]\n", "Hello", "world", INT_MAX, LONG_MIN, 0, LONG_MAX);
    check(i, j);

    printf("\n=============== flag case ===============\n");
    printf("\n=== 0 flag ===\n");
    i = printf("[%0d]\n", INT_MIN);
    j = ft_printf("[%0d]\n", INT_MIN);
    check(i, j);

    i = printf("[%020d]\n", INT_MIN);
    j = ft_printf("[%020d]\n", INT_MIN);
    check(i, j);

    i = printf("[%010d]\n", INT_MIN);
    j = ft_printf("[%010d]\n", INT_MIN);
    check(i, j);

    i = printf("[%0-10d]\n", INT_MIN);
    j = ft_printf("[%0-10d]\n", INT_MIN);
    check(i, j);

    i = printf("[%0s]\n", "abcd");
    j = ft_printf("[%0s]\n", "abcd");
    check(i, j);

    i = printf("[%010s]\n", "abcd");
    j = ft_printf("[%010s]\n", "abcd");
    check(i, j);

    i = printf("[%010p]\n", INT_MAX);
    j = ft_printf("[%010p]\n", INT_MAX);
    check(i, j);

    i = printf("[%010p]\n", INT_MIN);
    j = ft_printf("[%010p]\n", INT_MIN);
    check(i, j);
    
    i = printf("[%020p]\n", INT_MIN);
    j = ft_printf("[%020p]\n", INT_MIN);
    check(i, j);

    printf("\n=== . flag ===\n");
    i = printf("[%.d]\n", INT_MIN);
    j = ft_printf("[%.d]\n", INT_MIN);
    check(i, j);

    i = printf("[%.10d]\n", INT_MIN);
    j = ft_printf("[%.10d]\n", INT_MIN);
    check(i, j);

    i = printf("[%.20d]\n", INT_MIN);
    j = ft_printf("[%.20d]\n", INT_MIN);
    check(i, j);

    i = printf("[%.10d]\n", INT_MIN);
    j = ft_printf("[%.10d]\n", INT_MIN);
    check(i, j);

    i = printf("[%.s]\n", "abcd");
    j = ft_printf("[%.s]\n", "abcd");
    check(i, j);

    i = printf("[%.10s]\n", "abcd");
    j = ft_printf("[%.10s]\n", "abcd");
    check(i, j);

    i = printf("[%.1s]\n", "abcd");
    j = ft_printf("[%.1s]\n", "abcd");
    check(i, j);

    i = printf("[%.1p]\n", INT_MAX);
    j = ft_printf("[%.1p]\n", INT_MAX);
    check(i, j);

    i = printf("[%.15p]\n", INT_MAX);
    j = ft_printf("[%.15p]\n", INT_MAX);
    check(i, j);

    printf("\n=== - flag ===\n");
    i = printf("[%-d]\n", INT_MIN);
    j = ft_printf("[%-d]\n", INT_MIN);
    check(i, j);

    i = printf("[%-10d]\n", INT_MIN);
    j = ft_printf("[%-10d]\n", INT_MIN);
    check(i, j);

    i = printf("[%-20d]\n", INT_MIN);
    j = ft_printf("[%-20d]\n", INT_MIN);
    check(i, j);

    i = printf("[%-s]\n", "abcd");
    j = ft_printf("[%-s]\n", "abcd");
    check(i, j);

    i = printf("[%-20s]\n", "abcd");
    j = ft_printf("[%-20s]\n", "abcd");
    check(i, j);

    i = printf("[%-1s]\n", "abcd");
    j = ft_printf("[%-1s]\n", "abcd");
    check(i, j);

    printf("\n=== multi flag ===\n");
    i = printf("[%-01s]\n", "abcd");
    j = ft_printf("[%-01s]\n", "abcd");
    check(i, j);

    i = printf("[%-010s]\n", "abcd");
    j = ft_printf("[%-010s]\n", "abcd");
    check(i, j);

    i = printf("[%0-1s]\n", "abcd");
    j = ft_printf("[%0-1s]\n", "abcd");
    check(i, j);

    i = printf("[%0-10s]\n", "abcd");
    j = ft_printf("[%0-10s]\n", "abcd");
    check(i, j);
    
    i = printf("[%-1.1s]\n", "abcd");
    j = ft_printf("[%-1.1s]\n", "abcd");
    check(i, j);

    i = printf("[%-10.1s]\n", "abcd");
    j = ft_printf("[%-10.1s]\n", "abcd");
    check(i, j);

    i = printf("[%-10.10s]\n", "abcd");
    j = ft_printf("[%-10.10s]\n", "abcd");
    check(i, j);

    i = printf("[%01.1s]\n", "abcd");
    j = ft_printf("[%01.1s]\n", "abcd");
    check(i, j);

    i = printf("[%010.1s]\n", "abcd");
    j = ft_printf("[%010.1s]\n", "abcd");
    check(i, j);
    
    i = printf("[%010.1s]\n", "abcd");
    j = ft_printf("[%010.1s]\n", "abcd");
    check(i, j);

    printf("=============== \*, m$ ===============\n");
    i = printf("[%0*d]\n", 10, 100);
    j = ft_printf("[%0*d]\n", 10, 100);
    check(i, j);

    printf("\n");
    i = printf("[%0*d]\n", -100, 100);
    j = ft_printf("[%0*d]\n", -100, 100);
    check(i, j);

    printf("\n");
    i = printf("[%d%d%01$d]\n", -100, 100, 100, 100);
    //j = ft_printf("[%03$d]\n", -100, 100, 10);
    //check(i, j);

    printf("\n");
    i = printf("[%d%d%01$d]\n", -100, 100, 100, 100);
    //j = ft_printf("[%03$d]\n", -100, 100, 10);
    //check(i, j);

   printf("=============== large str ===============\n");
   long long lll = 1LL * INT_MAX + 10LL;
   char *s = (char *)calloc(lll, sizeof(char));
   memset(s, 'a', lll-1);
   long ll;
   long ll2;
   ll = printf("%s\n", s);
   ll2 = ft_printf("%s\n", s);
   check(ll, ll2);

    printf("large number width\n");
    long long ll3 = printf("%02147483648d\n", 0);
    long long ll4 = ft_printf("%02147483648d\n", 0);
    check(ll3, ll4);

//     ll = printf("%-2147483648d\n", 0);
//     ll2 = ft_printf("%-2147483648d\n", 0);
//     check(ll, ll2);

    // printf("large number precision\n");
    // ll = printf("%.2147483648d\n", 0);
    // printf("%ld\n", ll);
    // ll2 = ft_printf("%.2147483648d\n", 0);
    // check(ll, ll2);

    i = printf("%p %p\n", LONG_MIN, LONG_MAX);
    j = ft_printf("%p %p\n", LONG_MIN, LONG_MAX);

    i = printf("%p %p\n", ULONG_MAX, -ULONG_MAX);
    j = ft_printf("%p %p\n", ULONG_MAX, -ULONG_MAX);

    printf("=============== error case ===============\n");
    i = printf("[%d]\n", "abcd");
    j = ft_printf("[%d]\n", "abcd");
    check(i, j);

    int ii = printf("[%]\n");
    int jj = ft_printf("[%]\n");
    check(ii, jj);

    ii = printf("[%d%s%d]\n", 1234, "abcd");
    jj = ft_printf("[%d%s%d]\n", 1234, "abcd");
    check(ii, jj);

    ii = printf("[%d]\n");
    jj = ft_printf("[%d]\n");
    check(ii, jj);
}
