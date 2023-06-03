/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 08:00:04 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/03 08:00:04 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	check_count_eaten(t_info *info);
static int	check_dead(t_info *info);

int	check_state(t_info *info)
{
	return (check_count_eaten(info) || check_dead(info));
}

static int	check_count_eaten(t_info *info)
{
	int	i;

	i = 0;
	if (info->times_to_eat == -1)
		return (FALSE);
	while (i < info->num_philos)
	{
		pthread_mutex_lock(&info->philos[i].count_eaten_lock);
		if (info->count_eaten[i] != info->times_to_eat)
		{
			pthread_mutex_unlock(&info->philos[i].count_eaten_lock);
			return (FALSE);
		}
		pthread_mutex_unlock(&info->philos[i].count_eaten_lock);
		i ++;
	}
	pthread_mutex_lock(&info->finished_lock);
	info->died = TRUE;
	pthread_mutex_unlock(&info->finished_lock);
	return (TRUE);
}

static int	check_dead(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philos)
	{
		pthread_mutex_lock(&info->philos[i].time_last_eaten_lock);
		if (gettime(info) - info->philos[i].time_last_eaten
			>= info->time_to_die)
		{
			pthread_mutex_unlock(&info->philos[i].time_last_eaten_lock);
			pthread_mutex_lock(&info->finished_lock);
			info->died = TRUE;
			pthread_mutex_unlock(&info->finished_lock);
			print_message(info, DIED, RED, i);
			return (TRUE);
		}
		pthread_mutex_unlock(&info->philos[i].time_last_eaten_lock);
		i ++;
	}
	return (FALSE);
}
