/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:35:38 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/19 16:45:21 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	g_str[4];

void	check_unicode(unsigned char c, int *uni_bytes, int *i)
{
	if (*uni_bytes == 0)
	{
		if (c >= 240)
			*uni_bytes = 4;
		else if (c >= 224)
			*uni_bytes = 3;
		else if (c >= 192)
			*uni_bytes = 2;
		else
			*uni_bytes = 1;
	}
	g_str[*i] = c;
	(*i)++;
	if (*i == *uni_bytes)
	{
		write(1, g_str, *uni_bytes);
		*i = 0;
		*uni_bytes = 0;
		ft_memset(g_str, 0, 4);
	}
}

void	reset_data(int *i, int *uni, unsigned char *c, int *shift)
{
	*shift = 7;
	*c = 0;
	*i = 0;
	*uni = 0;
	ft_memset(g_str, 0, 4);
}

void	send_response(unsigned char c, int pid)
{
	if (c == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_printf("Server failed to send SIGUSR1");
	}
}

void	handler_s(int signum, siginfo_t *info, void *ucontent)
{
	static unsigned char	c;
	static int				shift_it = 7;
	static pid_t			pid;
	static int				uni_bytes;
	static int				i;

	(void)ucontent;
	if (info->si_pid != pid)
	{
		pid = info->si_pid;
		reset_data(&i, &uni_bytes, &c, &shift_it);
	}
	if (signum == SIGUSR2)
		c |= (1 << shift_it);
	shift_it--;
	if (shift_it < 0)
	{
		check_unicode(c, &uni_bytes, &i);
		send_response(c, info->si_pid);
		shift_it = 7;
		c = 0;
	}
}

void	sa_config(void)
{
	struct sigaction	sa;

	if (sigemptyset(&sa.sa_mask) == -1)
		ft_printf("Failed to Change Signal's Behavior");
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler_s;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Failed to Change Signal's Behavior");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Failed to Change Signal's Behavior");
}
