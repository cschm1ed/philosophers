/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_dead.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:18:38 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/12 15:21:55 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"


int	check_for_dead(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philos)
	{
		if (info->table->philos[i]->state == dead)
		{
			ft_putnbr(gettime);
			ft_putstr(" ");
			ft_putnbr(info->table->philos[i]->position);
			ft_putstr(" has died\n");
			return (1);
		}
		i ++;
	}
	return (0);
}
