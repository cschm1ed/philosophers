/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:40:06 by cschmied          #+#    #+#             */
/*   Updated: 2023/05/28 16:40:06 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	free_info(t_info *info)
{
	int i;

	i = 0;
	free(info->philos);
	while (i < info->num_philos)
		pthread_mutex_destroy(&info->locks[i++]);
	free(info->times_eaten);
}