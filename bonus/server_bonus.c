/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:22:04 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/19 16:49:03 by obouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	main(int ac, char *av[])
{
	pid_t	pid;

	(void)av;
	if (ac != 1)
		return (1);
	welcome_msg();
	pid = getpid();
	ft_printf("\t\t\t  \x1b[32m• \x1b[32mServer Is Running");
	ft_printf("\n\t\t\t       PID: %d\x1b[0m\n\n", pid);
	sa_config();
	while (1)
		pause();
	return (0);
}
