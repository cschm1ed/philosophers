/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:00:08 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/22 19:18:21 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0
# define USAGE "Usage: ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n"
# define ERROR_INPUT "ERROR: argument must be positive integer.\n"

typedef struct s_info t_info;

enum state
{
	eating = 0,
	sleeping = 1,
	thinking = 2,
	dead = 3,
};

typedef struct s_philo
{
	int				pos;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	enum state		state;
	t_info			*info;
}	t_philo;

typedef	struct s_info
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int 			count_eat;
	int				starttime;
	t_philo			*philos;
	pthread_mutex_t	*locks;
}	t_info;

void	*philo(void *arg);
int		join_threads(t_info *info);

int	gettime(int starttime);


// utils
int		ft_putstr(const char *str);
int		ft_atoi(const char *str);
void	*ft_calloc(int count, int size);
int		info_init(int argc, char **argv, t_info *info);

#endif