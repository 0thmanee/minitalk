/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:48:20 by obouchta          #+#    #+#             */
/*   Updated: 2023/11/01 17:48:23 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c2;
	char	*location;
	int		i;

	c2 = (char)c;
	location = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c2)
			location = ((char *)(s + i));
		i++;
	}
	if (s[i] == c2)
		location = ((char *)(s + i));
	return (location);
}
