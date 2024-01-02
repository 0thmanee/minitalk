/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:03:41 by obouchta          #+#    #+#             */
/*   Updated: 2023/11/14 22:55:18 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

int	ft_printf(const char	*str, ...);
int	ft_format(va_list args, char c);
int	ft_printc(char c);
int	ft_prints(char *s);
int	ft_printd(int d);
int	ft_printu(int d);
int	ft_printbase(unsigned long d2, char *base);
int	ft_printp(void *d, char *base);
int	ft_printx(unsigned int x, char c);

#endif
