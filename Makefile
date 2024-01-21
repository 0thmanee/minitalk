CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rc
PRINTF = ft_printf/libftprintf.a

NAMECLIENT = client
CCLIENT = ./mandatory/client.c ./mandatory/tools.c
OBJCLIENT = $(CCLIENT:.c=.o)
HEADERMAND = ./mandatory/minitalk.h

NAMESERVER = server
CSERVER = ./mandatory/server.c ./mandatory/tools.c
OBJSERVER = $(CSERVER:.c=.o)

NAMECLIENTBONUS = client_bonus
CCLIENTBONUS = ./bonus/client_bonus.c ./bonus/tools_bonus.c
OBJCLIENTBONUS = $(CCLIENTBONUS:.c=.o)
HEADERBONUS = ./bonus/minitalk_bonus.h

NAMESERVERBONUS = server_bonus
CSERVERBONUS = ./bonus/server_bonus.c ./bonus/tools_bonus.c ./bonus/tools2_bonus.c
OBJSERVERBONUS = $(CSERVERBONUS:.c=.o)

CPRINTF = ./ft_printf/ft_printf.c ./ft_printf/ft_printc.c ./ft_printf/ft_prints.c ./ft_printf/ft_printd.c ./ft_printf/ft_printu.c ./ft_printf/ft_printp.c ./ft_printf/ft_printx.c
OBJPRINTF = $(CPRINTF:.c=.o)

all: $(NAMECLIENT) $(NAMESERVER)

bonus: $(NAMECLIENTBONUS) $(NAMESERVERBONUS)

$(NAMECLIENT): $(OBJCLIENT) $(OBJPRINTF)
	@$(CC) $(CFLAGS) $^ -o $@

$(NAMESERVER): $(OBJSERVER) $(OBJPRINTF)
	@$(CC) $(CFLAGS) $^ -o $@

$(NAMECLIENTBONUS): $(OBJCLIENTBONUS) $(OBJPRINTF)
	@$(CC) $(CFLAGS) $^ -o $@

$(NAMESERVERBONUS): $(OBJSERVERBONUS) $(OBJPRINTF)
	@$(CC) $(CFLAGS) $^ -o $@

ft_printf/%.o: ft_printf/%.c $(HEADERMAND) $(HEADERBONUS)
	@$(CC) $(CFLAGS) -c $< -o $@

mandatory/%.o: mandatory/%.c $(HEADERMAND)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c $(HEADERBONUS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJCLIENT) $(OBJSERVER) $(OBJCLIENTBONUS) $(OBJSERVERBONUS) $(OBJPRINTF)

fclean: clean
	@$(RM) $(NAMECLIENT) $(NAMESERVER) $(NAMECLIENTBONUS) $(NAMESERVERBONUS) $(PRINTF)

re: fclean all

.PHONY: all clean fclean re bonus
