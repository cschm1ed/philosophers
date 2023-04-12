/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:26:09 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/12 15:16:33 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int    info_init(int argc, char **argv, t_info *info)
{
    if (argc < 5 || argc > 6)
        return (write(2, "USAGE: ./philo number_of_philosophers", 38),
                write(2, "time_to_die time_to_eat time_to_sleep", 38),
                write(2, "[number_of_times_each_philosopher_must_eat].\n", 46),
                -1);
    info->table = malloc(sizeof(t_table*));
    if (!info->table)
        return (-1);
    info->num_philos = ft_atoi(argv[1]);
    if (info->num_philos == -1)
        return (-1);
    info->time_to_die = ft_atoi(argv[2]);
    if (info->time_to_die == -1)
        return (-1);
    info->time_to_eat = ft_atoi(argv[3]);
    if (info->time_to_eat == -1)
        return (-1);
    info->time_to_sleep = ft_atoi(argv[4]);
    if (info->time_to_sleep == -1)
        return (-1);
    if (argc == 6)
    {
        info->to_eat = ft_atoi(argv[5]);
        if (info->to_eat == -1)
            return (-1);
    }
    return (0);
}

int table_init(t_info *info, t_table *table)
{
    table->fork_states = malloc(sizeof(pthread_mutex_t) * info->num_philos);
    if (!table->fork_states)
        return (perror("malloc"), try_clean(info), -1);
    table->philos = malloc(sizeof(t_philo*) * info->num_philos * sizeof(t_philo*));
    if (!table->philos)
        return (perror("malloc"), try_clean(info), -1);
    return (0);
}
