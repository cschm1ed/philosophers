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
	printf("hello there (num %d)\n", self->pos);
	return (NULL);
}

int main(int argc, char **argv)
{
	t_info		info;

	if (info_init(argc, argv, &info) == -1)
		return (1);
	if (join_threads(&info) == -1)
		return (0);
	return (0);
}

int	join_threads(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philos)
	{
		if (pthread_join(info->philos[i].thread, NULL) != 0)
			return (-1);
		i ++;
	}
	return (0);
}
