/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:22:12 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/12 15:27:43 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int  ft_strlen(const char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
        i ++;
    return (i);
}

void    ft_putstr(const char *str)
{
    write(1, str, ft_strlen(str));
}
