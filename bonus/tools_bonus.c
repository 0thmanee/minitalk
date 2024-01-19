/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:50:58 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/19 16:48:16 by obouchta         ###   ########.fr       */
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

void	welcome_msg(void)
{
	ft_printf("\x1b[32m");
	usleep(10000);
	ft_printf("%s%s%s%s%s", INTRO1, INTRO2, INTRO3, INTRO4, INTRO5);
	ft_printf("%s%s%s%s%s\n\n", INTRO6, INTRO7, INTRO8, INTRO9, INTRO10);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	result;
	long	tmp;

	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		tmp = (result * 10) + (str[i] - 48);
		if (tmp < result)
			return (2147483648);
		result = tmp;
		i++;
	}
	return (result);
}

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*ptr2;

	ptr2 = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		ptr2[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}
