CC := gcc
CFLAGS := -Wall -Wextra -Werror
NAME := ft_printf
LIBFT := libft.a
SRCS := *.c
OBJS := $(SRCS:.c=.o)

all: $(NAME) $(LIBFT)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o: $(SRCS)
	$(CC) $(CFLAGS) $@ $^

$(LIBFT) : $(LIBFT_OBJS)
	ar rc $@ $^

.c.o: $(LIBFT_SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(LIBFT_OBJS) $(OBJS)

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
	