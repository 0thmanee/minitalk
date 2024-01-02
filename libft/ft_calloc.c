/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:01:36 by obouchta          #+#    #+#             */
/*   Updated: 2023/11/14 09:11:12 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	bytes;
	void	*str;

	if ((size && count > (4294967295 / size)))
		return (NULL);
	if ((int) count < 0 && (int) size < 0)
		return (NULL);
	bytes = count * size;
	str = malloc(bytes);
	if (!str)
		return (NULL);
	ft_bzero(str, bytes);
	return (str);
}
