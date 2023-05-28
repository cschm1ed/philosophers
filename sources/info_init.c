	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:15:44 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/22 19:19:31 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	create_locks(t_info *info);
static int	philos_init(t_info *info);

int	info_init(int argc, char **argv, t_info *info)
{
	if (!(argc == 5 || argc == 6))
		return (ft_putstr(USAGE));
	memset(info, 0, sizeof(t_info));
	if (argc == 6)
		info->times_to_eat = ft_atoi(argv[5]);
	info->num_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->times_eaten = ft_calloc(info->num_philos, sizeof(int));
	if (info->times_eaten == NULL)
		return (perror("malloc"), FAILURE);
	if (pthread_mutex_init(&info->start_lock, NULL) != 0
		|| pthread_mutex_init(&info->print_lock, NULL) != 0
		|| pthread_mutex_init(&info->times_eaten_lock, NULL) != 0
		|| pthread_mutex_init(&info->finished_lock, NULL) != 0)
		return (perror("mutex_init"), FAILURE);
	if (info->num_philos == -1 || info->time_to_die == -1
		|| info->time_to_eat == -1 || info->time_to_sleep == -1)
		return (ft_putstr(ERROR_INPUT), FAILURE);
	info->locks = ft_calloc(sizeof(pthread_mutex_t), info->num_philos);
	if (!info->locks)
		return (perror("malloc"), FAILURE);
	pthread_mutex_lock(&info->start_lock);
	if (create_locks(info) == FAILURE || philos_init(info) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int	philos_init(t_info *info)
{
	int	i;

	i = 0;
	info->philos = ft_calloc(info->num_philos, sizeof(t_philo));
	if (!info->philos)
		return (perror("malloc"), FAILURE);
	while (i < info->num_philos)
	{
		info->philos[i].pos = i;
		info->philos[i].time_last_eaten = 0;
		if (pthread_create(&(info->philos[i].thread),
			NULL, philo, (void*)(&info->philos[i])) != 0)
			return (perror("malloc"), FAILURE);
		if (i == 0)
			info->philos[i].left_fork = &info->locks[info->num_philos - 1];
		else
			info->philos[i].left_fork = &info->locks[i - 1];
		info->philos[i].right_fork = &info->locks[i];
		info->philos[i].info = info;
		i ++;
	}
	return (SUCCESS);
}

static int	create_locks(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philos)
	{
		if (pthread_mutex_init(&(info->locks[i]), NULL) != 0)
			return (FAILURE);
		i ++;
	}
	return (SUCCESS);
}
