/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:52:28 by obouchta          #+#    #+#             */
/*   Updated: 2023/11/24 17:32:56 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, char c)
{
	int	bytes;
	int	j;

	bytes = 0;
	if (c == '%')
		j = ft_printc(c);
	else if (c == 'c')
		j = ft_printc(va_arg(args, int));
	else if (c == 's')
		j = ft_prints(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		j = ft_printd(va_arg(args, int));
	else if (c == 'u')
		j = ft_printu(va_arg(args, unsigned int));
	else if (c == 'p')
		j = ft_printp(va_arg(args, void *), "0123456789abcdef");
	else if (c == 'x' || c == 'X')
		j = ft_printx(va_arg(args, unsigned int), c);
	else
		j = ft_printc(c);
	if (j != -1)
		bytes += j;
	else
		return (-1);
	return (bytes);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		j;
	int		bytes;

	va_start(args, str);
	i = 0;
	bytes = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1])
				j = ft_format(args, str[++i]);
		}
		else
			j = ft_printc(str[i]);
		if (j != -1)
			bytes += j;
		else
			return (-1);
		i++;
	}
	va_end(args);
	return (bytes);
}
