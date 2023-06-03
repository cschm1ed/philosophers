/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:00:08 by cschmied          #+#    #+#             */
/*   Updated: 2023/05/30 21:19:01 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define TRUE 1
# define FALSE 0
# define FAILURE -1
# define SUCCESS 0

# define US1 "Usage: ./philo number_of_philosophers time_to_die "
# define US2 "time_to_eat time_to_sleep "
# define US3 "[number_of_times_each_philosopher_must_eat]\n"

# define ERROR_INPUT "ERROR: argument must be positive integer.\n"

# define WAIT_INTERVAL 150
# define PAUSE_CHECK 20

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>
# include "philo_structs.h"
# include "../sources/utils/utils.h"

void	*philo(void *arg);
int		check_state(t_info *info);

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

#endif