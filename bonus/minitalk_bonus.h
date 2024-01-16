/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:22:25 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/16 19:58:45 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

void	*ft_memset(void *ptr, int value, size_t num);
int		send_sig(int bit, int pid);
void	send_empty(int pid);
long	ft_atoi(const char *str);
int		ft_printf(const char *format, ...);

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
