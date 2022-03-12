CC = gcc
INCLUDE = ft_printf.h
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT = libft/libft.a
SRCS_DIR = srcs/
SRCS_FILES = ft_printf.c\
		udsp_to_string.c\

SRCS := $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS := $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	cp $(LIBFT) $@
	ar rc $@ $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $< 

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
