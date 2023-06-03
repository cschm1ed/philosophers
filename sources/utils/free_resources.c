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
	pthread_mutex_destroy(&info->finished_lock);
	pthread_mutex_destroy(&info->start_lock);
	pthread_mutex_destroy(&info->print_lock);
	while (i < info->num_philos)
	{
		pthread_mutex_destroy(&info->philos[i].count_eaten_lock);
		pthread_mutex_destroy(&info->philos[i].time_last_eaten_lock);
		pthread_mutex_destroy(&info->locks[i++]);
	}
	free(info->count_eaten);
	free(info->philos);
}