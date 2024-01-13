/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:04:01 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/12 22:38:12 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (signum == SIGUSR2)
		c |= (1 << shift_it);
	shift_it--;
	if (shift_it < 0)
	{
		ft_putchar_fd(c, 1);
		c = 0;
		shift_it = 7;
	}
}

void	sa_config(void)
{
	struct sigaction	sa;

	
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Failed to Change Signal's Behavior");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Failed to Change Signal's Behavior");
}

void	welcome_msg(void)
{
	ft_printf("\x1b[32m");
	usleep(10000);
	ft_printf("%s%s%s%s%s", INTRO1, INTRO2, INTRO3, INTRO4, INTRO5);
	ft_printf("%s%s%s%s%s\n\n", INTRO6, INTRO7, INTRO8, INTRO9, INTRO10);
}

int	main(int ac, char *av[])
{
	pid_t	pid;

	(void)av;
	if (ac != 1)
		return (1);
	welcome_msg();
	pid = getpid();
	ft_printf("\t\t\t  \x1b[32m• \x1b[32mServer Is Running");
	ft_printf("\n\t\t\t       PID: %d\x1b[0m\n\n", pid);
	while (1)
		sa_config();
}
