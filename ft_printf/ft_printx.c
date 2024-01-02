/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:03:26 by obouchta          #+#    #+#             */
/*   Updated: 2023/11/14 22:54:53 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printx(unsigned int x, char c)
{
	int	bytes;
	int	j;

	bytes = 0;
	if (c == 'x')
		j = ft_printbase(x, "0123456789abcdef");
	else
		j = ft_printbase(x, "0123456789ABCDEF");
	if (j != -1)
		bytes += j;
	else
		return (-1);
	return (bytes);
}
