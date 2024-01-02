/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:37:54 by obouchta          #+#    #+#             */
/*   Updated: 2023/11/14 10:20:26 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prints(char *s)
{
	int	j;
	int	bytes;

	bytes = 0;
	if (s == NULL)
	{
		j = write(1, "(null)", 6);
		if (j != -1)
			bytes += j;
		else
			return (-1);
	}
	else
	{
		while (*s)
		{
			j = ft_printc(*s);
			if (j != -1)
				bytes += j;
			else
				return (-1);
			s++;
		}
	}
	return (bytes);
}
