/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 04:12:16 by oer-refa          #+#    #+#             */
/*   Updated: 2024/04/06 04:12:17 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

size_t  ft_strlen(const char *str){

    size_t  i;

    i = 0;
    while (str[i])
        i++;
    return(i);
}