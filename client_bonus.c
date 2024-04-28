/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 04:14:05 by oer-refa          #+#    #+#             */
/*   Updated: 2024/04/27 21:53:29 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_bit(char c, pid_t server_pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
		{
			if (kill(server_pid, SIGUSR1) == -1)
			{
				ft_putstr("problem in send signal");
				exit(1);
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
			{
				ft_putstr("problem in send signal");
				exit(1);
			}
		}
		usleep(300);
		bit--;
	}
}

void	end_sind(int sig)
{
	if (sig == SIGUSR2)
		ft_putstr("message is send");
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	char	*str;
	int		i;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		str = argv[2];
		if (server_pid <= 0 || server_pid > 2147483647)
		{
			ft_putstr("PID Invalid");
			exit(1);
		}
		signal(SIGUSR2, end_sind);
		i = 0;
		while (str[i])
		{
			send_bit(str[i], server_pid);
			i++;
			usleep(300);		
		}
		send_bit(str[i], server_pid);
		
	}
	else
		(ft_putstr("problem with the number of arg (PID or message)"), exit(1));
	return (0);
}
