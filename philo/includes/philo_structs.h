/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:59:07 by cschmied          #+#    #+#             */
/*   Updated: 2023/05/30 21:36:13 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCTS_H
# define PHILO_STRUCTS_H

# include <philo.h>

typedef struct s_info	t_info;
typedef struct s_shared	t_shared;

typedef struct s_philo
{
	int				pos;
	long			time_last_eaten;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	count_eaten_lock;
	pthread_mutex_t	time_last_eaten_lock;
	t_info			*info;
}	t_philo;

typedef struct s_info
{
	int				died;
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_to_eat;
	int				*count_eaten;
	long			starttime;
	t_philo			*philos;
	pthread_mutex_t	*locks;
	pthread_mutex_t	finished_lock;
	pthread_mutex_t	start_lock;
	pthread_mutex_t	print_lock;
}	t_info;

#endif
