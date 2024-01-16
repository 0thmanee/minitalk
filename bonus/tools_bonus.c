/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:50:58 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/16 18:54:45 by obouchta         ###   ########.fr       */
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

long calc_result(long result, char c)
{
	long	tmp;

	tmp = (result * 10) + (c - 48);
	if (tmp < result)
		return (2147483648);
	return (tmp);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = calc_result(result, str[i]);
		i++;
	}
	return (result);
}
