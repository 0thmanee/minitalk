/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:22:04 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/16 20:00:11 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	check_unicode(unsigned char *c, int *shift_it, int *uni_bytes, int *i)
{
	static char	*str;
	
	if (*shift_it < 0)
	{
		if (*c >= 240)
			*uni_bytes = 4;
		else if (*c >= 224)
			*uni_bytes = 3;
		else if (*c >= 192)
			*uni_bytes = 2;
		else
			*uni_bytes = 1;
		(*i)++;
		str[*i] = *c;
		if (*i == *uni_bytes)
		{
			ft_printf("%s", str);
			*i = 0;
			ft_memset(str, 0, 4);
		}
		c = 0;
		*shift_it = 7;
	}
}

void	handler(int signum, siginfo_t *info, void *ucontent)
{
	static unsigned char	c;
	static int				shift_it = 7;
	static pid_t			pid;
	static int				uni_bytes;
	static int				i;

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
	if (c == 0)
	{
		if (kill(info->si_pid, SIGUSR1) == -1)
			ft_printf("Server failed to send SIGUSR1");
	}
	check_unicode(&c, &shift_it, &uni_bytes, &i);
}

void	sa_config(void)
{
	struct sigaction	sa;

	if (sigemptyset(&sa.sa_mask) == -1)
		ft_printf("Failed to Change Signal's Behavior");
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
