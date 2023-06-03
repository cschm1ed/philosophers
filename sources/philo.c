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

static void	try_eat_then_sleep(t_philo *self);

void	*philo(void *arg)
{
	t_philo	*self;

	self = (t_philo *)arg;
	pthread_mutex_lock(&self->info->start_lock);
	pthread_mutex_unlock(&self->info->start_lock);
	if (self->pos % 2)
	{
		print_message(self->info, THINK, YELLOW, self->pos);
		ft_wait(self->info->time_to_eat / 2);
	}
	pthread_mutex_lock(&self->info->finished_lock);
	while (self->info->died == FALSE)
	{
		pthread_mutex_unlock(&self->info->finished_lock);
		try_eat_then_sleep(self);
		print_message(self->info, THINK, BLUE, self->pos);
		pthread_mutex_lock(&self->count_eaten_lock);
		self->info->count_eaten[self->pos] += 1;
		pthread_mutex_unlock(&self->count_eaten_lock);
		pthread_mutex_lock(&self->info->finished_lock);
	}
	pthread_mutex_unlock(&self->info->finished_lock);
	return (NULL);
}

static void	try_eat_then_sleep(t_philo *self)
{


	pthread_mutex_lock(self->right_fork);
	print_message(self->info, FORK, CYAN, self->pos);
	pthread_mutex_lock(self->left_fork);
	print_message(self->info, FORK, CYAN, self->pos);

	print_message(self->info, EAT, GREEN, self->pos);
	ft_wait(self->info->time_to_eat);
	pthread_mutex_unlock(self->right_fork);
	pthread_mutex_unlock(self->left_fork);

	pthread_mutex_lock(&self->count_eaten_lock);
	self->info->count_eaten[self->pos] += 1;
	pthread_mutex_unlock(&self->count_eaten_lock);

	pthread_mutex_lock(&self->time_last_eaten_lock);
	self->time_last_eaten = gettime(self->info);
	pthread_mutex_unlock(&self->time_last_eaten_lock);
	print_message(self->info, SLEEP, YELLOW, self->pos);
	ft_wait(self->info->time_to_sleep);
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
