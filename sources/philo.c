/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:14:29 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/22 19:20:13 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo(void *arg)
{
	t_philo	*self;

	self = (t_philo*)arg;
	pthread_mutex_lock(&self->info->start_lock);
	pthread_mutex_unlock(&self->info->start_lock);
	pthread_mutex_lock(&self->info->finished_lock);
	while (self->info->died == FALSE)
	{
		pthread_mutex_unlock(&self->info->finished_lock);
		if (self->pos % 2 == 1)
		{
			pthread_mutex_lock(self->right_fork);
			print_taken_fork(self->info, self->pos);
			pthread_mutex_lock(self->left_fork);
			print_taken_fork(self->info, self->pos);
		}
		else
		{
			pthread_mutex_lock(self->left_fork);
			print_taken_fork(self->info, self->pos);
			pthread_mutex_lock(self->right_fork);
			print_taken_fork(self->info, self->pos);
		}
		print_eating(self->info, self->pos);
		ft_wait(self->info->time_to_eat);
		self->info->times_eaten[self->pos] += 1;

		pthread_mutex_unlock(self->right_fork);
		pthread_mutex_unlock(self->left_fork);

		pthread_mutex_lock(&self->info->times_eaten_lock);
		self->time_last_eaten = gettime(self->info);
		pthread_mutex_unlock(&self->info->times_eaten_lock);

		print_sleeping(self->info, self->pos);
		ft_wait(self->info->time_to_sleep);

		print_thinking(self->info, self->pos);

		pthread_mutex_lock(&self->info->times_eaten_lock);
		if (gettime(self->info) +  self->info->times_to_eat <
			self->time_last_eaten + self->info->time_to_die)
			usleep(1000 * self->info->time_to_eat);
		pthread_mutex_unlock(&self->info->times_eaten_lock);

		pthread_mutex_lock(&self->info->finished_lock);
	}
	return (NULL);
}


int	join_threads(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philos)
	{
		if (pthread_join(info->philos[i].thread, NULL) != 0)
			return (FAILURE);
		i ++;
	}
	return (SUCCESS);
}

