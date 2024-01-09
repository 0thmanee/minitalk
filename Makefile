CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a

NAMECLIENT = client
CCCLIENT = ./mandatory/client.c
OBJCLIENT = $(CCCLIENT:.c=.o)

NAMESERVER = server
CCSERVER = ./mandatory/server.c
OBJSERVER = $(CCSERVER:.c=.o)

NAMECLIENTBONUS = client_bonus
CCCLIENTBONUS = ./bonus/client_bonus.c
OBJCLIENTBONUS = $(CCCLIENTBONUS:.c=.o)

NAMESERVERBONUS = server_bonus
CCSERVERBONUS = ./bonus/server_bonus.c
OBJSERVERBONUS = $(CCSERVERBONUS:.c=.o)

all: $(NAMECLIENT) $(NAMESERVER)
	@echo "Server Created"
	@echo "Client Created"

bonus: $(NAMECLIENTBONUS) $(NAMESERVERBONUS)
	@echo "Server Created"
	@echo "Client Created"

$(NAMECLIENT): $(OBJCLIENT)
	@make -C ./libft
	@make -C ./ft_printf
	@$(CC) $(CFLAGS) $(OBJCLIENT) $(LIBFT) $(PRINTF) -o $(NAMECLIENT)

$(NAMESERVER): $(OBJSERVER)
	@make -C ./libft
	@make -C ./ft_printf
	@$(CC) $(CFLAGS) $(OBJSERVER) $(LIBFT) $(PRINTF) -o $(NAMESERVER)

$(NAMECLIENTBONUS): $(OBJCLIENTBONUS)
	@make -C ./libft
	@make -C ./ft_printf
	@$(CC) $(CFLAGS) $(OBJCLIENTBONUS) $(LIBFT) $(PRINTF) -o $(NAMECLIENTBONUS)

$(NAMESERVERBONUS): $(OBJSERVERBONUS)
	@make -C ./libft
	@make -C ./ft_printf
	@$(CC) $(CFLAGS) $(OBJSERVERBONUS) $(LIBFT) $(PRINTF) -o $(NAMESERVERBONUS)

clean:
	@make clean -C ./libft
	@make clean -C ./ft_printf
	@$(RM) $(OBJCLIENT) $(OBJSERVER) $(OBJCLIENTBONUS) $(OBJSERVERBONUS)

fclean: clean 
	@make -s fclean -C ./libft
	@make -s fclean -C ./ft_printf
	@$(RM) $(NAMECLIENT) $(NAMESERVER) $(NAMECLIENTBONUS) $(NAMESERVERBONUS)

re: fclean bonus clean