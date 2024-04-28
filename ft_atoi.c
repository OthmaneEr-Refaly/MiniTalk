/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 04:12:09 by oer-refa          #+#    #+#             */
/*   Updated: 2024/04/26 09:33:01 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

long int	ft_atoi(const char *str)
{
	long int			i;
	long int			sin;
	unsigned long long	rus;

	i = 0;
	sin = 1;
	rus = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sin = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		rus = rus * 10 + (str[i] - '0');
		i++;
	}
	if (str[i])
		return (0);
	return (rus * sin);
}
