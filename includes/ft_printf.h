#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "../libft/includes/libft.h"
#include <stdbool.h>
#include <stdio.h>

enum {
    // FLAG_NONE,
    FLAG_ZERO = 1,
    FLAG_DOT = 2,
    FLAG_MINUS = 4,
    FLAG_SHARP = 8,
    FLAG_SPACE = 16,
    FLAG_PLUS = 32,
};
typedef struct {
    int  flag;
    bool is_precision;
    char c;
    size_t field_width;
    size_t precision;
} pflag;

int number_of_digits(long long n);
int ft_printf(const char *fmt, ...);
pflag	*consume(const char **fmt, va_list *ap);
char *u_to_string(va_list *ap);
char *d_to_string(va_list *ap);
char *p_to_string(va_list *ap);
char *x_to_string(va_list *ap, char c);
int	write_c(const char **fmt, pflag *flag, va_list *ap);
int	write_s(pflag *flag, va_list *ap);
int	write_diu(const char **fmt, pflag *flag, va_list *ap);
int	write_xX(const char **fmt, pflag *flag, va_list *ap);
int	write_p(pflag *flag, va_list *ap);
int	write_flag_c(char c, int width);
#endif
