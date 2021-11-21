#include "ft_printf.h"

int put_pointer(const char *fmt, va_list ap)
{
    long long   pointer;

    pointer = va_arg(ap, long long);

}
