/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:36:42 by cschmied          #+#    #+#             */
/*   Updated: 2023/05/28 12:36:42 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	ft_wait(long to_wait)
{
	struct timeval	tv;
	long			start;
	long			current;

	gettimeofday(&tv, NULL);
	start = tv.tv_usec / 1000 + tv.tv_sec * 1000;
	current = 0;
	while (current - start < to_wait)
	{
		gettimeofday(&tv, NULL);
		current = tv.tv_usec / 1000 + tv.tv_sec * 1000;
		usleep(WAIT_INTERVAL);
	}
}
