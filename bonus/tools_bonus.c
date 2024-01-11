/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:50:58 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/11 23:51:54 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

void	send_empty(int pid)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_printf("Client failed to send SIGUSR1");
		usleep(200);
		j--;
	}
}
