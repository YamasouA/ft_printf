#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "../libft/includes/libft.h"
#include <stdbool.h>
#include <stdio.h>
typedef struct {
    bool is_alignleft;
    bool is_padding;
    bool is_precision;
    bool is_specifier;
    bool is_alignspace;
    bool is_assign;
    char *convert;
    size_t field_width;
    size_t precision;
} pflag;

// typedef struct contents contents;
// struct contents{
//     size_t len;
//     char *text;
    
//     contents *next;
//     pflag *flag;
// };
int ft_printf(const char *fmt, ...);
int	put_chr(va_list ap);
int	put_str(va_list ap);
int	put_decimal(va_list ap);
int put_unsigned_decimal(va_list ap);
int put_hex(va_list ap, int size);
// int put_p(va_list ap);
// void apply_alignleft(contents *list);
// char *apply_padding(char *str, pflag *flag);
pflag	*consume(const char **fmt);
char	*apply_flag(char *str, pflag *flag);
char *apply_precision(char *str, pflag *flag);
// char *apply_specifier(contents *list);
// char *apply_alignspace(contents *list);
// char *apply_assign(contents *list);
char    *c_to_string(char c, int *c_null);
char *u_to_string(va_list *ap);
char *d_to_string(va_list *ap);
char *s_to_string(va_list *ap);
char *p_to_string(va_list *ap);
char *x_to_string(va_list *ap, int type);
// size_t concat_contents();
// contents *new_contents(const char *fmt, va_list ap, char *text);
// pflag *flag_consume(const char *fmt);
// void free_list(contents *cont);
#endif
