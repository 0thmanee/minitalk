/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:37:49 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/16 18:08:14 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/minitalk.h"

static int	ft_putnbr(int d)
{
	int	bytes;
	int	j;

	bytes = 0;
	if (d >= 10)
	{
		j = ft_putnbr(d / 10);
		if (j != -1)
			bytes += j;
		else
			return (-1);
	}
	j = ft_printc((d % 10) + '0');
	if (j != -1)
		bytes += j;
	else
		return (-1);
	return (bytes);
}

static int	ft_not_min(int d)
{
	int	bytes;
	int	j;

	bytes = 0;
	if (d < 0)
	{
		d = -d;
		j = ft_printc('-');
		if (j != -1)
			bytes += j;
		else
			return (-1);
	}
	j = ft_putnbr(d);
	if (j != -1)
		bytes += j;
	else
		return (-1);
	return (bytes);
}

int	ft_printd(int d)
{
	int		bytes;
	int		j;

	bytes = 0;
	if (d == -2147483648)
	{
		j = ft_prints("-2147483648");
		if (j != -1)
			return (11);
		else
			return (-1);
	}
	j = ft_not_min(d);
	if (j != -1)
		bytes += j;
	else
		return (-1);
	return (bytes);
}
