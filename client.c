/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 04:12:06 by oer-refa          #+#    #+#             */
/*   Updated: 2024/04/18 14:27:15 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

void send_bits(char c, pid_t pid)
{
    int bit;

    bit = 7;
    while (bit >= 0)
    {
        if ((c >> bit ) & 1)
        {
            if (kill(pid, SIGUSR1) == -1)
            {
                ft_putstr("signal not sent");
                exit(1);
            }
        }
        else
        {
            if (kill(pid, SIGUSR2) == -1)
            {
                ft_putstr("signal not sent");
                exit(1);
            }
        }
        usleep(150);
        bit--;
    }
}

int main(int argc, char *argv[])
{
    int i;
    char *str;
    long int pid;

    if (argc == 3)
    {   
        pid = ft_atoi(argv[1]);
        str = argv[2];
        if(pid <= 0 || pid > 2147483647 || ft_strlen(argv[1]) > 12)
        {
            ft_putstr("Invalid PID");
            exit(1);
        }
        i = 0;
        while (str[i])
        {
            send_bits(str[i], pid);
            i++;
        }
        send_bits(str[i], pid);
    }
        else
            ft_putstr("check the argements (PID or MESSAGE)");
        exit(1);
        return(0);
    }
