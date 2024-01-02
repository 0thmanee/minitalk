/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:16:49 by obouchta          #+#    #+#             */
/*   Updated: 2023/11/14 09:14:36 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*s3;
	const char	*s4;
	size_t		i;

	s3 = (const char *)s1;
	s4 = (const char *)s2;
	i = 0;
	while (i < n && s3[i] == s4[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s3[i] - (unsigned char)s4[i]);
}
