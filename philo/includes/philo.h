/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:20:27 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/12 15:34:24 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

//messages
# define TAKE_FORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "has died"

enum action
{
    thinking = 0,
    eating = 1,
    dead = 2 
} state;

typedef struct s_philo
{
    int             position;
    pthread_t       thread;
    enum action     state;
}   t_philo;

typedef struct s_table
{
    pthread_mutex_t     *fork_states;
    t_philo **philos;
}   t_table;

typedef struct s_info
{
    t_table         *table;
    pthread_mutex_t start_game;
    int             num_philos;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             to_eat;
}   t_info;

//utils
int     ft_atoi(const char *str);
void    try_clean(t_info *info);
int	check_for_dead(t_info *info);

//inits
int info_init(int argc, char **argv, t_info *info);
int table_init(t_info *info, t_table *table);

#endif