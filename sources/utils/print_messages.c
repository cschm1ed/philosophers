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

void	print_message(t_info *info, const char *msg, char* color, int pos)
{
	pthread_mutex_lock(&info->finished_lock);
	if (info->died == FALSE || *msg == 'd')
	{
		pthread_mutex_lock(&info->print_lock);
		printf("%s %lu %d %s %s\n", color, gettime(info), pos + 1, msg, RESET);
		pthread_mutex_unlock(&info->print_lock);
	}
	pthread_mutex_unlock(&info->finished_lock);
}
