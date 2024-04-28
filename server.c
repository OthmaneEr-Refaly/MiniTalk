/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:51:42 by oer-refa          #+#    #+#             */
/*   Updated: 2024/04/26 09:54:26 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handeler(int sig)
{
	static char	s;
	static int	bit;

	if (sig == SIGUSR1)
	{
		s = (s << 1) | 1;
		bit++;
	}
	else if (sig == SIGUSR2)
	{
		s = (s << 1);
		bit++;
	}
	if (bit == 8)
	{
		write(1, &s, 1);
		s = 0;
		bit = 0;
	}
}

int	main(int argc, char *argv[])
{
	char	*pid;

	(void)argv;
	if (argc == 1)
	{
		pid = ft_itoa(getpid());
		signal(SIGUSR1, signal_handeler);
		signal(SIGUSR2, signal_handeler);
		ft_putstr("Server PID is = ");
		ft_putstr(pid);
		free(pid);
		ft_putstr("\n");
		while (1)
		{
		}
		return (0);
	}
	else
		ft_putstr("Check the argumentes");
	exit(1);
}
