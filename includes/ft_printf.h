#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct {
    bool is_alignleft;
    bool is_padding;
    bool is_precision;
    bool is_specifier;
    bool is_alignspace;
    bool is_assign;
} flag;

typedef struct contents;
struct contents{
    size_t len;
    char *text;
    contents *next;
    flag *flag;
}

typedef enum {
    TY_N;
    TY_U;
    TY_D;
    TY_S;
    TY_C;
    TY_x;
    TY_X;
    TY_P;
} typekind;

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
int ft_printf(const char *fmt, ...);
int	put_chr(va_list ap);
int	put_str(va_list ap);
int	put_decimal(va_list ap);
int put_unsigned_decimal(va_list ap);
int put_hex(va_list ap, int size);
int put_p(va_list ap);
size_t concat_contents()
contents *new_contents()

#endif
