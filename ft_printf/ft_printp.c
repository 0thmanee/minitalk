/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:42:19 by obouchta          #+#    #+#             */
/*   Updated: 2023/11/14 22:40:44 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printbase(unsigned long d2, char *base)
{
	int	bytes;
	int	j;

	bytes = 0;
	if (d2 >= 16)
	{
		j = ft_printbase(d2 / 16, base);
		if (j != -1)
			bytes += j;
		else
			return (-1);
	}
	j = ft_printc(base[(d2 % 16)]);
	if (j != -1)
		bytes += j;
	else
		return (-1);
	return (bytes);
}

int	ft_printp(void *d, char *base)
{
	int				bytes;
	int				j;
	unsigned long	d2;

	bytes = 0;
	j = ft_prints("0x");
	if (j != -1)
		bytes += j;
	else
		return (-1);
	d2 = (unsigned long)d;
	j = ft_printbase(d2, base);
	if (j != -1)
		bytes += j;
	else
		return (-1);
	return (bytes);
}
