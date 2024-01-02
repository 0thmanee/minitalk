/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:49:20 by obouchta          #+#    #+#             */
/*   Updated: 2023/11/14 22:41:13 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(unsigned int d)
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

int	ft_printu(int d)
{
	int	bytes;
	int	j;

	bytes = 0;
	j = ft_putnbr(d);
	if (j != -1)
		bytes += j;
	else
		return (-1);
	return (bytes);
}
