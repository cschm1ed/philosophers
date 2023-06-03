/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:48:30 by cschmied          #+#    #+#             */
/*   Updated: 2023/05/28 21:37:45 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	create_locks(t_info *info);
static int	philos_init(t_info *info);
static int	read_input(int argc, char **argv, t_info *info);
static int	create_shared_locks(t_info *info);

int	info_init(int argc, char **argv, t_info *info)
{
	info->died = FALSE;
	if (read_input(argc, argv, info) == FAILURE)
		return (FAILURE);
	if (create_shared_locks(info) == FAILURE)
		return (perror("mutex init"), FAILURE);
	pthread_mutex_lock(&info->start_lock);
	info->locks = ft_calloc(sizeof(pthread_mutex_t), info->num_philos);
	if (info->locks == NULL
		|| create_locks(info) == FAILURE
		|| philos_init(info) == FAILURE)
		return (perror("malloc"), FAILURE);
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
		info->philos[i].info = info;
		info->philos[i].pos = i;
		info->philos[i].time_last_eaten = 0;
		if (pthread_mutex_init(&info->philos[i].count_eaten_lock, NULL)
			|| pthread_mutex_init(&info->philos[i].time_last_eaten_lock, NULL))
			return (perror("mutex_init"), FAILURE);
		if (i == 0)
			info->philos[i].left_fork = &info->locks[info->num_philos - 1];
		else
			info->philos[i].left_fork = &info->locks[i - 1];
		info->philos[i].right_fork = &info->locks[i];
		if (pthread_create(&(info->philos[i].thread),
				NULL, philo, (void*)(&info->philos[i])) != 0)
			return (perror("malloc"), FAILURE);
		i ++;
	}
	return (SUCCESS);
}

static int	read_input(int argc, char **argv, t_info *info)
{
	if (!(argc == 5 || argc == 6))
		return (printf("%s%s%s", US1, US2, US3), FAILURE);
	if (argc == 6)
	{
		if (ft_isint(argv[5]) == FALSE)
			return (FAILURE);
		info->times_to_eat = ft_atoi(argv[5]);
	}
	else
		info->times_to_eat = -1;
	if (ft_isint(argv[1]) == FALSE
		|| ft_isint(argv[2]) == FALSE
		|| ft_isint(argv[3]) == FALSE
		|| ft_isint(argv[4]) == FALSE)
		return (printf("%s%s%s", US1, US2, US3), printf(ERROR_INPUT), FAILURE);
	info->num_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->count_eaten = ft_calloc(info->num_philos, sizeof(int));
	if (info->count_eaten == NULL)
		return (perror("malloc"), FAILURE);
	return (SUCCESS);
}

static int	create_shared_locks(t_info *info)
{
	if (pthread_mutex_init(&info->start_lock, NULL) != 0
		|| pthread_mutex_init(&info->print_lock, NULL) != 0
		|| pthread_mutex_init(&info->finished_lock, NULL) != 0)
		return (FAILURE);
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
