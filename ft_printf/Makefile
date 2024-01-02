NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rc

RM = rm -f

FILES = ft_printf.c ft_printc.c ft_prints.c ft_printd.c\
ft_printu.c ft_printp.c ft_printx.c\

OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $^

%.o: %.c ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re
