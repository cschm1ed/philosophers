/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:28:57 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/12 15:32:39 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void    philo_log(int time, int pos, char *msg)
{
    ft_putnbr(time);
    ft_putstr(" ");
    ft_putnbr(pos);
    ft_putstr(msg);
    ft_putstr("\n");
}
