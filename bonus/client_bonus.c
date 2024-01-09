#include "minitalk_bonus.h"

int	invalid_args(int ac, char *av[])
{
	int	i;

	if (ac != 3)
	{
		ft_printf("\x1b[31mYou Must Enter 3 arguments, no less no more :/\n");
		return (1);
	}
	i = 0;
	while (av[1][i])
	{
		if (av[1][i] < '0' || av[1][i] > '9')
		{
			ft_printf("\x1b[31mYour PID Should Contains Only Digits :~\n");
			return (1);
		}
		i++;
	}
	if (av[2][0] == '\0')
		return (1);
	return (0);
}

void	handler(int signum)
{
	if(signum == SIGUSR1)
		ft_printf("\x1b[32m• \x1b[32mMessage Receaved Successufly By The Server\n");
}

void	sa_config()
{
	struct sigaction	sa;
	
	sa.sa_flags = SIGINFO;
	sa.sa_handler = &handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Failed to Change Signal's Behavior");
}

void	send_msg(int pid, char *msg){
	int		i;
	int		j;
	char	bit;
	char	c;
	char	empty;

	i = 0;
	bit = 0;
	empty = 0;
	while (msg[i])
	{
		j = 7;
		c = msg[i];
		while (j >= 0)
		{
			bit = (c >> j & 1);
			if (bit == 0)
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_printf("Client failed to send SIGUSR1");
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_printf("Client failed to send SIGUSR2");
			}
			usleep(200);
			j--;
		}
		i++;
	}
	j = 7;
	while (j >= 0)
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_printf("Client failed to send SIGUSR1");
		usleep(200);
		j--;
	}
}

int	main(int ac, char *av[])
{
	pid_t	pid;

	if (invalid_args(ac, av))
		return (1);
	pid = ft_atoi(av[1]);
	sa_config();
	send_msg(pid, av[2]);
}