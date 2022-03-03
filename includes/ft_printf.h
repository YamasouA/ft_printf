#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct {
    bool is_alignleft;
    bool is_padding;
    bool is_precision;
    bool is_specifier;
    bool is_alignspace;
    bool is_assign;
    char *convert;
    size_t precision;
    size_t padding;
} pflag;

typedef struct contents;
struct contents{
    size_t len;
    char *text;
    
    contents *next;
    pflag *flag;
}


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
void apply_alignleft(contents *list);
void apply_padding(contents *list);
void apply_precision(contents *list);
void apply_specifier(contents *list);
void apply_alignspace(contents *list);
void apply_assign(contents *list);
char *u_to_string(va_list ap, pflag *flag);
char *d_to_string(va_list ap, pflag *flag);
char *s_to_string(va_list ap, pflag *flag);
char *p_to_string(va_list ap, pflag *flag);
char *x_to_string(va_list ap, int type, pflag *flag);
size_t concat_contents();
contents *new_contents(const char *fmt, va_list ap, typekind kind);
pflag *flag_consume(const char *fmt);
void free_list(contents *cont);

#endif
