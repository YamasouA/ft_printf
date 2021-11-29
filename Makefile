CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
NAME = libftprintf.a
SRCS = ft_printf.c\
		ft_printf_c.c\
		ft_printf_d.c\
		ft_printf_h.c\
		ft_printf_s.c\
		ft_printf_u.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re