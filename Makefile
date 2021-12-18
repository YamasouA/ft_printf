CC = gcc
INCLUDE = ft_printf.h
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c\
		ft_printf_c.c\
		ft_printf_d.c\
		ft_printf_h.c\
		ft_printf_s.c\
		ft_printf_u.c\
		ft_printf_p.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -I./$(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
