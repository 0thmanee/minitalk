/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:22:42 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/11 23:31:49 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	send_sig(int bit, int pid)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_printf("Server failed to send SIGUSR1");
			return (0);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_printf("Server failed to send SIGUSR2");
			return (0);
		}
	}
	return (1);
}

void	send_msg(int pid, char *msg)
{
	int		i;
	int		j;
	char	bit;
	char	c;

	i = -1;
	bit = 0;
	while (msg[++i])
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
	}
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
	send_msg(pid, av[2]);
	return (0);
}
