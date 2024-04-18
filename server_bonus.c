/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 04:12:03 by oer-refa          #+#    #+#             */
/*   Updated: 2024/04/06 04:12:48 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_signal(int sig, siginfo_t *info, void *str)
{
	static char	s;
	static int	bit;

	(void)str;
	if (sig == SIGUSR1)
		s = (s << 1) | 1;
	else if (sig == SIGUSR2)
		s = (s << 1);
	bit++;
	if (bit == 8)
	{
		if (s == '\0')
			kill(info->si_pid, SIGUSR1);
		else
			write(1, &s, 1);
		s = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	char				*pid;

	pid = ft_itoa(getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_signal;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr("sigaction error ");
		exit(1);
	}
	ft_putstr("server PID: ");
	ft_putstr(pid);
	free(pid);
	ft_putstr("\n");
	while (1)
	{
	}
	return (0);
}