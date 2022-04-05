#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "../libft/includes/libft.h"
#include <stdbool.h>
#include <stdio.h>

typedef enum {
    FLAG_NONE,
    FLAG_ZERO,
    FLAG_DOT,
    FLAG_MINUS,
    FLAG_SHARP,
    FLAG_SPACE,
    FLAG_PLUS,
} fl;
typedef struct {
    // bool is_alignleft;
    // bool is_padding;
    // bool is_precision;
    // bool is_specifier;
    // bool is_alignspace;
    // bool is_assign;
    fl  fl_type;
    bool is_precision;
    char *convert;
    size_t field_width;
    size_t precision;
} pflag;

typedef struct {
    int size_width;
    int size_pre;
} size_width;

// typedef struct contents contents;
// struct contents{
//     size_t len;
//     char *text;
    
//     contents *next;
//     pflag *flag;
// };
int number_of_digits(int n);
int ft_printf(const char *fmt, ...);
int	put_chr(va_list ap);
int	put_str(va_list ap);
int	put_decimal(va_list ap);
int put_unsigned_decimal(va_list ap);
int put_hex(va_list ap, int size);
// int put_p(va_list ap);
// void apply_alignleft(contents *list);
// char *apply_padding(char *str, pflag *flag);
pflag	*consume(const char **fmt, va_list *ap);
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

int	write_c(const char **fmt, pflag *flag, va_list *ap);
size_t	write_s(pflag *flag, va_list *ap);
int	write_diu(const char **fmt, pflag *flag, va_list *ap);
int	write_xX(const char **fmt, pflag *flag, va_list *ap);
int	write_p(pflag *flag, va_list *ap);
int	write_flag_c(char c, int width);
#endif
