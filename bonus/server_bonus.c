/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouchta <obouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:22:04 by obouchta          #+#    #+#             */
/*   Updated: 2024/01/21 02:58:53 by obouchta         ###   ########.fr       */
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
	ft_printf("\t\t\t  Server Is Running");
	ft_printf("\n\t\t\t       PID: %d\n\n", pid);
	sa_config();
	while (1)
		pause();
	return (0);
}
