/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:06:09 by cschmied          #+#    #+#             */
/*   Updated: 2023/05/28 13:06:09 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	print_eating(t_info *info, int num)
{
	long time;

	time = gettime(info);
	pthread_mutex_lock(&info->print_lock);
	printf(MAGENTA"%li %d is eating\n"RESET, time, num + 1);
	pthread_mutex_unlock(&info->print_lock);
}

void	print_sleeping(t_info *info, int num)
{
	long time;

	time = gettime(info);
	pthread_mutex_lock(&info->print_lock);
	printf(BLUE"%li %d is sleeping\n"RESET, time, num + 1);
	pthread_mutex_unlock(&info->print_lock);
}

void	print_thinking(t_info *info, int num)
{
	long time;

	time = gettime(info);
	pthread_mutex_lock(&info->print_lock);
	printf(CYAN"%li %d is thinking\n"RESET, time, num + 1);
	pthread_mutex_unlock(&info->print_lock);
}

void	print_died(t_info *info, int num)
{
	long time;

	time = gettime(info);
	pthread_mutex_lock(&info->print_lock);
	printf(RED"%li %d died\n"RESET, time, num + 1);
	pthread_mutex_unlock(&info->print_lock);
}

void	print_taken_fork(t_info *info, int num)
{
	long time;

	time = gettime(info);
	pthread_mutex_lock(&info->print_lock);
	printf(GREEN"%li %d has taken a fork\n"RESET, time, num + 1);
	pthread_mutex_unlock(&info->print_lock);
}
