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
	if (argc == 6)
		info->count_eat = -1;
	info->num_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (info->num_philos == -1 || info->time_to_die == -1
		|| info->time_to_eat == -1 || info->time_to_sleep == -1)
		return (ft_putstr(ERROR_INPUT), -1);
	info->locks = ft_calloc(sizeof(pthread_mutex_t), info->num_philos);
	if (!info->locks)
		return (write(1, "malloc error\n", 14), -1);
	if (create_locks(info) == -1 || philos_init(info) == -1)
		return (-1);
	return (0);
}

static int	philos_init(t_info *info)
{
	int	i;

	i = 0;
	info->philos = ft_calloc(info->num_philos, sizeof(t_philo));
	if (!info->philos)
		return (-1);
	while (i < info->num_philos)
	{
		info->philos[i].pos = i;
		if (pthread_create(&(info->philos[i].thread),
			NULL, philo, (void*)(&info->philos[i])) != 0)
			return (-1);
		if (i == 0)
			info->philos[i].left_fork = &info->locks[info->num_philos - 1];
		else
			info->philos[i].left_fork = &info->locks[i - 1];
		info->philos[i].right_fork = &info->locks[i];
		info->philos[i].info = info;
		i ++;
	}
	return (0);
}

static int	create_locks(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philos)
	{
		if (pthread_mutex_init(&(info->locks[i]), NULL) != 0)
			return (-1);
		i ++;
	}
	return (0);
}
