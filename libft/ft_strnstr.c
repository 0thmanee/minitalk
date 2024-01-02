/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:34:10 by obouchta          #+#    #+#             */
/*   Updated: 2023/11/14 09:16:35 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *bg, const char *sml, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!sml[i])
		return ((char *)bg);
	while (i < len && bg[i])
	{
		j = 0;
		while ((i + j) < len && bg[i + j] && sml[j] && bg[i + j] == sml[j])
			j++;
		if (j == ft_strlen(sml))
			return ((char *)bg + i);
		i++;
	}
	return (NULL);
}
