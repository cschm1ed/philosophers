/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:27:44 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/12 15:28:05 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void writenbr_recursively(int n)
{
    char    digit;

    if (n == 0)
        return;
    else
        writenbr_recursively(n / 10);
    digit = n % 10 + '0';
    write (1, &digit, 1);
}

void    ft_putnbr(int n)
{
    int i;

    if (n == 0)
    {
        write(1, "0", 1);
        return ;
    }
    writenbr_recursively(n);
}

