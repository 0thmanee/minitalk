/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:24:15 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/28 11:43:52 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <stdarg.h>

long	ft_atoi(const char *str);
int		ft_printf(const char	*str, ...);
int		ft_format(va_list args, char c);
int		ft_printc(char c);
int		ft_prints(char *s);
int		ft_printd(int d);
int		ft_printu(int d);
int		ft_printbase(unsigned long d2, char *base);
int		ft_printp(void *d, char *base);
int		ft_printx(unsigned int x, char c);

# define INTRO1 "\n\n\t               /$$           /$$   /$$               /$$"
# define INTRO2 " /$$      \n\t              |__/          |__/  | $$          "
# define INTRO3 "    | $$| $$      \n\t /$$$$$$/$$$$  /$$ /$$$$$$$  /$$ /$$$$$$"
# define INTRO4 "    /$$$$$$ | $$| $$   /$$\n\t| $$_  $$_  $$| $$| $$__  $$| $$"
# define INTRO5 "|_  $$_/   |____  $$| $$| $$  /$$/\n\t| $$ \\ $$ \\ $$| $$| $$"
# define INTRO6 "  \\ $$| $$  | $$      /$$$$$$$| $$| $$$$$$/ \n\t| $$ | $$ | $"
# define INTRO7 "$| $$| $$  | $$| $$  | $$ /$$ /$$__  $$| $$| $$_  $$ \n\t| $$ "
# define INTRO8 "| $$ | $$| $$| $$  | $$| $$  |  $$$$/|  $$$$$$$| $$| $$ \\  $$"
# define INTRO9 "\n\t|__/ |__/ |__/|__/|__/  |__/|__/   \\___/   \\_______/|__/"
# define INTRO10 "|__/  \\__/\n"
#endif