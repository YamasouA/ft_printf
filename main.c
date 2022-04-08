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
}

void d_check(int d)
{
    int i, j;
    i = printf("%d\n", d);
    j = ft_printf("%d\n", d);
    check(i, j);
}

void i_check(int d)
{
    int i, j;
    i = printf("%i\n", d);
    j = ft_printf("%i\n", d);
    check(i, j);
}

void c_check(char c)
{
    int i, j;
    i = printf("%c\n", c);
    j = ft_printf("%c\n", c);
    check(i, j);
}

void s_check(char *s)
{
    int i, j;
    i = printf("%s\n", s);
    j = ft_printf("%s\n", s);
    check(i, j);
}

void u_check(unsigned int u)
{
    int i, j;
    i = printf("%u\n", u);
    j = ft_printf("%u\n", u);
    check(i, j);
}

void p_check(long long p)
{
    int i, j;
    i = printf("%p\n", p);
    j = ft_printf("%p\n", p);
    check(i, j);
}

void x_check(long long x)
{
    int i, j;
    i = printf("%x\n", x);
    j = ft_printf("%x\n", x);
    check(i, j);
}

void X_check(long long x)
{
    int i, j;
    i = printf("%X\n", x);
    j = ft_printf("%X\n", x);
    check(i, j);
}

int main()
{
    // i = ft_printf("%c %d %s\n", c, n, s);
    // printf("i: %d\n", i);

    // printf("%s\n", sss("abc"));
    // printf("%%\n");
    // printf("%%\n");
    // ft_printf("%%\n");

    // printf("\n");

    printf("=============== text only =============\n");
    int k = printf("Hello World !!\n");
    int l = ft_printf("Hello World !!\n");
    check(k, l);
    k = printf("\tabcd\n");
    l = ft_printf("\tabcd\n");
    check(k, l);

    printf("=============== %%d ===============\n");
    // printf("printf:INT_MIN\t-> %d\n", INT_MIN);
    // ft_printf("ft_printf:INT_MIN\t-> %d\n", INT_MIN);
    // printf("printf:INT_MAX\t-> %d\n", INT_MAX);
    // ft_printf("ft_printf:INT_MAx\t-> %d\n", INT_MAX);
    // printf("printf:0\t-> %d\n", 0);
    // ft_printf("ft_printf:0\t-> %d\n", 0);
    d_check(1234);
    d_check(-1234);
    d_check(INT_MAX);
    d_check(INT_MIN);
    d_check(0);

    // printf("\n");

    printf("=============== %%i ===============\n");
    // printf("printf:INT_MIN\t-> %i\n", INT_MIN);
    // ft_printf("ft_printf:INT_MIN\t-> %i\n", INT_MIN);
    // printf("printf:INT_MAX\t-> %i\n", INT_MAX);
    // ft_printf("ft_printf:INT_MAx\t-> %i\n", INT_MAX);
    // printf("printf:0\t-> %i\n", 0);
    // ft_printf("ft_printf:0\t-> %i\n", 0);
    i_check(1234);
    i_check(-1234);
    i_check(INT_MAX);
    i_check(INT_MIN);
    i_check(0);

    // printf("\n");

    printf("=============== %%s ===============\n");
    // printf("printf:\t%s\n", s);
    // ft_printf("ft_printf:\t%s\n", s);
    // printf("printf:\t%s\n", s2);
    // ft_printf("ft_printf:\t%s\n", s2);
    s_check("abcd");
    s_check("\n");
    s_check("");
    s_check("Hello World");

    // printf("\n");

    printf("=============== %%c ===============\n");
    // printf("printf:\t%c\n", *s);
    // ft_printf("ft_printf:\t%c\n", *s);
    // printf("printf:\t%c\n", c);
    // ft_printf("ft_printf:\t%c\n", c);
    c_check('a');
    c_check('\n');
    c_check(' ');
    c_check(100);
    c_check(128);

    // printf("\n");

    ft_printf("=============== %%x ===============\n");
    // ft_printf("255\t-> %x\n", 255);
    // ft_printf("0\t-> %x\n", 0);
    // ft_printf("9\t-> %x\n", 9);
    // ft_printf("10\t-> %x\n", 10);
    // ft_printf("15\t-> %x\n", 15);
    // ft_printf("16\t-> %x\n", 16);
    // ft_printf("-10\t-> %x\n", -10);
    // ft_printf("-15\t-> %x\n", -15);
    // ft_printf("-16\t-> %x\n", -16);
    // ft_printf("INT_MIN\t-> %x\n", INT_MIN);
    // ft_printf("INT_MAX\t-> %x\n", INT_MAX);

    // printf("\n");
    // printf("printf %%x\n");

    // printf("255\t-> %x\n", 255);
    // printf("0\t-> %x\n", 0);
    // printf("9\t-> %x\n", 9);
    // printf("10\t-> %x\n", 10);
    // printf("15\t-> %x\n", 15);
    // printf("16\t-> %x\n", 16);
    // printf("-10\t-> %x\n", -10);
    // printf("-15\t-> %x\n", -15);
    // printf("-16\t-> %x\n", -16);
    // printf("INT_MIN\t-> %x\n", INT_MIN);
    // printf("INT_MAX\t-> %x\n", INT_MAX);
    x_check(255);
    x_check(-255);
    x_check(15);
    x_check(-15);
    x_check(16);
    x_check(-16);
    x_check(0);
    x_check(INT_MAX);
    x_check(INT_MIN);
    x_check(LONG_MAX);
    x_check(LONG_MIN);

    // printf("\n");
    ft_printf("=============== %%X ===============\n");
    // ft_printf("255\t-> %X\n", 255);
    // ft_printf("0\t-> %X\n", 0);
    // ft_printf("9\t-> %X\n", 9);
    // ft_printf("10\t-> %X\n", 10);
    // ft_printf("15\t-> %X\n", 15);
    // ft_printf("16\t-> %X\n", 16);
    // ft_printf("-10\t-> %X\n", -10);
    // ft_printf("-15\t-> %X\n", -15);
    // ft_printf("-16\t-> %X\n", -16);
    // ft_printf("INT_MIN\t-> %X\n", INT_MIN);
    // ft_printf("INT_MAX\t-> %X\n", INT_MAX);
    X_check(255);
    X_check(-255);
    X_check(15);
    X_check(-15);
    X_check(16);
    X_check(-16);
    X_check(0);
    X_check(INT_MAX);
    X_check(INT_MIN);
    X_check(LONG_MAX);
    X_check(LONG_MIN);
    // ft_printf("\n");

    printf("=============== %%u ===============\n");
    // printf("printf:255\t-> %u\n", 255);
    // ft_printf("ft_printf:255\t-> %u\n", 255);
    // printf("printf:0\t-> %u\n", 0);
    // ft_printf("ft_printf:0\t-> %u\n", 0);
    // printf("printf:UINT_MAX\t-> %u\n", UINT_MAX);
    // ft_printf("ft_printf:UINT_MAX\t-> %u\n", UINT_MAX);
    // printf("printf:-1\t-> %u\n", -1);
    // ft_printf("ft_printf:-1\t-> %u\n", -1);
    // printf("printf:-10\t-> %u\n", -10);
    // ft_printf("ft_printf:-10\t-> %u\n", -10);
    u_check(255);
    u_check(-255);
    u_check(0);
    u_check(UINT_MAX);
    u_check(INT_MAX);
    u_check(INT_MIN);
    u_check(LONG_MAX);
    u_check(LONG_MIN);

    // printf("\n");

    printf("=============== %%p ===============\n");
    // printf("printf:\t%p\n", &s);
    // ft_printf("ft_printf:\t%p\n", &s);
    // printf("printf:\t%p\n", &c);
    // ft_printf("ft_printf:\t%p\n", &c);
    // printf("printf:\t%p\n", &n);
    // ft_printf("ft_printf:\t%p\n", &n);
    // printf("printf:\t%p\n", -1);
    // ft_printf("ft_printf:\t%p\n", -1);
    // printf("printf:\t%p\n", -2);
    // ft_printf("ft_printf:\t%p\n", -2);
    // i = printf("%p %p\n", LONG_MIN, LONG_MAX);
    // printf("%d\n", i);
    // i = printf("%p %p\n", ULONG_MAX, -ULONG_MAX);
    // printf("%d\n", i);
    // i = ft_printf("%p %p\n", LONG_MIN, LONG_MAX);
    // printf("%d\n", i);
    // i = ft_printf("%p %p\n", ULONG_MAX, -ULONG_MAX);
    // printf("%d\n", i);
    p_check(INT_MIN);
    p_check(INT_MAX);
    p_check(0);
    p_check(LONG_MIN);
    p_check(LONG_MAX);
    p_check(UINT_MAX);
    p_check(ULLONG_MAX);

    // // /int i;
    printf("=============== NULL case ============\n");
    // printf("%%s\n");
    // i = printf("%s\n", NULL);
    // printf("NULL return %d\n", i);
    // i = ft_printf("%s\n", NULL);
    // printf("NULL return %d\n", i);
    // printf("%%p\n");
    // i = printf("%p\n", NULL);
    // printf("NULL return %d\n", i);
    // i = ft_printf("%p˜\n", NULL);
    // printf("NULL return %d\n", i);
    d_check(NULL);
    i_check(NULL);
    u_check(NULL);
    c_check(NULL);
    s_check(NULL);
    x_check(NULL);
    X_check(NULL);
    p_check(NULL);
    int x = printf("%cend\n", NULL);
    int y = ft_printf("%cend\n", NULL);
    printf("%d\n", x);
    printf("%d\n", y);
    printf("\n");

    x = printf(" %c %c %c \n", '0', 0, '1');
    y = ft_printf(" %c %c %c \n", '0', 0, '1');
    printf("%d\n", x);
    printf("%d\n", y);
    printf("\n");

    x = printf(" %c %c %c end\n", '2', '1', 0);
    y = ft_printf(" %c %c %c end\n", '2', '1', 0);
    printf("%d\n", x);
    printf("%d\n", y);
    printf("\n");

    x = printf(" %c %c %c \n", 0, '1', '2');
    y = ft_printf(" %c %c %c \n", 0, '1', '2');
    printf("%d\n", x);
    printf("%d\n", y);
    printf("\n");
    

    printf("=============== multiple format ===============\n");
    int i = printf("format %c %s %% %d %i %u %x %X %p\n", 'a', "HELLO", INT_MIN, INT_MAX, UINT_MAX, UINT_MAX, INT_MIN, ULONG_MAX);
    int j = ft_printf("format %c %s %% %d %i %u %x %X %p\n", 'a', "HELLO", INT_MIN, INT_MAX, UINT_MAX, UINT_MAX, INT_MIN, ULONG_MAX);
    printf("%d\n", i);
    printf("%d\n", j);
    printf("\n");

    i = printf("%s %s %d %p %p %x\n", "Hello", "world", INT_MAX, LONG_MIN, 0, LONG_MAX);
    j = ft_printf("%s %s %d %p %p %x\n", "Hello", "world", INT_MAX, LONG_MIN, 0, LONG_MAX);
    printf("%d\n", i);
    printf("%d\n", j);
    printf("\n");

    


    printf("=============== flag case ===============\n");
    printf("=== 0 flag ===\n");
    i = printf("%0d\n", INT_MIN);
    j = ft_printf("%0d\n", INT_MIN);

    i = printf("%0d\n", INT_MIN);
    j = ft_printf("%0d\n", INT_MIN);

    i = printf("%0d\n", INT_MIN);
    j = ft_printf("%0d\n", INT_MIN);

    i = printf("%0d\n", INT_MIN);
    j = ft_printf("%0d\n", INT_MIN);

    i = printf("%0d\n", INT_MIN);
    j = ft_printf("%0d\n", INT_MIN);


    printf("=============== large str ===============\n");
    long long lll = 1LL * INT_MAX + 1LL;
    char *s = (char *)malloc(lll * sizeof(char));
    memset(s, 'a', lll-1);
    long ll;
    long ll2;
    // ll = printf("%s\n", s);
    // ll2 = ft_printf("%s\n", s);
    // printf("i: %ld\n", ll);
    // printf("j: %ld\n", ll2);

    long long size = 1LL * INT_MAX + 10LL;
	char *str = (char *)malloc(size * sizeof(char));
	memset(str, '_', size - 1LL);
	str[size - 1LL] = '\0';
	// printf("%d\n", printf("ab\n%s", str));
	printf("%d\n", ft_printf("ab\n%s", str));
}
