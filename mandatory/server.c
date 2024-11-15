/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:04:01 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/21 02:28:54 by obouchta         ###   ########.fr       */
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
		ft_printf("%c", c);
		c = 0;
		shift_it = 7;
	}
}

void	sa_config(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Failed to Change Signal's Behavior");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Failed to Change Signal's Behavior");
}

void	welcome_msg(void)
{
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
	ft_printf("\t\t\t  Server Is Running");
	ft_printf("\n\t\t\t       PID: %d\n\n", pid);
	while (1)
		sa_config();
}
