CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a

NAMECLIENT = client
CCLIENT = ./mandatory/client.c
OBJCLIENT = $(CCLIENT:.c=.o)
HEADERMAND = ./mandatory/minitalk.h

NAMESERVER = server
CSERVER = ./mandatory/server.c
OBJSERVER = $(CSERVER:.c=.o)

NAMECLIENTBONUS = client_bonus
CCLIENTBONUS = ./bonus/client_bonus.c ./bonus/tools_bonus.c
OBJCLIENTBONUS = $(CCLIENTBONUS:.c=.o)
HEADERBONUS = ./bonus/minitalk_bonus.h

NAMESERVERBONUS = server_bonus
CSERVERBONUS = ./bonus/server_bonus.c
OBJSERVERBONUS = $(CSERVERBONUS:.c=.o)

LIBS = $(LIBFT) $(PRINTF)

all: $(LIBFT) $(PRINTF) $(NAMECLIENT) $(NAMESERVER)

bonus: $(LIBFT) $(PRINTF) $(NAMECLIENTBONUS) $(NAMESERVERBONUS)

$(LIBFT):
	@make -C ./libft

$(PRINTF):
	@make -C ./ft_printf

$(NAMECLIENT): $(OBJCLIENT)
	@$(CC) $(CFLAGS) $(OBJCLIENT) $(LIBS) -o $(NAMECLIENT)
	@printf "\033[32m[ ✔ ] %s\n\033[0m" "Client created"

$(NAMESERVER): $(OBJSERVER)
	@$(CC) $(CFLAGS) $(OBJSERVER) $(LIBS) -o $(NAMESERVER)
	@printf "\033[32m[ ✔ ] %s\n\033[0m" "Server created"

mandatory/%.o: mandatory/%.c $(HEADERMAND)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c $(HEADERBONUS)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAMECLIENTBONUS): $(OBJCLIENTBONUS)
	@$(CC) $(CFLAGS) $(OBJCLIENTBONUS) $(LIBS) -o $(NAMECLIENTBONUS)
	@printf "\033[32m[ ✔ ] %s\n\033[0m" "Clientbonus created"

$(NAMESERVERBONUS): $(OBJSERVERBONUS)
	@$(CC) $(CFLAGS) $(OBJSERVERBONUS) $(LIBS) -o $(NAMESERVERBONUS)
	@printf "\033[32m[ ✔ ] %s\n\033[0m" "Serverbonus created"

clean:
	@$(RM) $(OBJCLIENT) $(OBJSERVER) $(OBJCLIENTBONUS) $(OBJSERVERBONUS) libft/*.o ft_printf/*.o

fclean: clean
	@$(RM) $(NAMECLIENT) $(NAMESERVER) $(NAMECLIENTBONUS) $(NAMESERVERBONUS) $(LIBFT) $(PRINTF)
	@make -s fclean -C ./libft
	@make -s fclean -C ./ft_printf

re: fclean all

.PHONY: all clean fclean re bonus
