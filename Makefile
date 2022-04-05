CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT = libft/libft.a
SRCS_DIR = srcs/
SRCS_FILES = ft_printf.c\
		udsp_to_string.c\
		consume.c\
		apply.c\
		utils.c\
		write_diu.c\

SRCS := $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS := $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $< 

$(LIBFT): empty
	make -C libft

empty:

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

test:
	gcc main.c $(NAME)
	./a.out

.PHONY: all clean fclean re
