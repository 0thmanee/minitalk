/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:22:17 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/12 01:07:20 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	invalid_args(int ac, char *av[])
{
	int	i;

	if (ac != 3)
	{
		ft_printf("\x1b[31m3 Arguments are required :/\n");
		return (1);
	}
	i = 0;
	if (av[1][i] == '+')
		i++;
	while (av[1][i])
	{
		if (av[1][i] < '0' || av[1][i] > '9')
		{
			ft_printf("\x1b[31mInvalid PID :~\n");
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
	if (signum == SIGUSR1)
	{
		ft_printf("\x1b[32m• \x1b[32m");
		ft_printf("Message Receaved Successufly By The Server\n");
	}
}

void	sa_config(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sa.sa_flags = SIGINFO;
	sa.sa_handler = &handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Failed to Change Signal's Behavior");
}

void	send_msg(int pid, char *msg)
{
	int		i;
	int		j;
	char	bit;
	char	c;

	i = 0;
	bit = 0;
	while (msg[i])
	{
		j = 7;
		c = msg[i];
		while (j >= 0)
		{
			bit = (c >> j & 1);
			if (!send_sig(bit, pid))
				return ;
			usleep(200);
			j--;
		}
		i++;
	}
	send_empty(pid);
}

int	main(int ac, char *av[])
{
	long	old_pid;
	pid_t	pid;

	if (invalid_args(ac, av))
		return (1);
	old_pid = ft_atoi(av[1]);
	if (old_pid <= 2 || old_pid > INT_MAX || kill(old_pid, 0) == -1)
	{
		ft_printf("\x1b[31mInvalid PID :~\n");
		return (1);
	}
	pid = (pid_t)old_pid;
	sa_config();
	send_msg(pid, av[2]);
	return (0);
}
