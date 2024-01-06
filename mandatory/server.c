#include "minitalk.h"

void	handler(int signum, siginfo_t *info, void *ucontent)
{
	static unsigned char	c;
	static int				shift_it = 7;
	static pid_t			pid;

	(void)ucontent;
	if (info->si_pid != pid)
	{
		shift_it = 7;
		c = 0;
		pid = info->si_pid;
	}
	if (shift_it < 0)
		shift_it = 7;
	if (signum == SIGUSR2)
		c |= (1 << shift_it);
	shift_it--;
	if (shift_it < 0)
	{
		ft_putchar_fd(c, 1);
		c = 0;
	}
}

void	sa_config()
{
	struct sigaction	sa;
	
	sa.sa_flags = SIGINFO;
	sa.sa_sigaction = &handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Failed to Change Signal's Behavior");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Failed to Change Signal's Behavior");
}

void	welcome_msg()
{
	ft_printf("\x1b[32m");
	usleep(10000);
	ft_printf("%s", INTRO);
}

int main(int ac, char *av[])
{
	pid_t				pid;

	(void)av;
	if (ac != 1)
		return (1);
	welcome_msg();
	pid = getpid();
	
	ft_printf("\t\t  \x1b[32m• \x1b[32mServer Is Running\n\t\t       PID: %d\x1b[0m\n\n", pid);
	while (1)
		sa_config();
}