/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:21:32 by cschmied          #+#    #+#             */
/*   Updated: 2023/05/20 19:21:32 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

unsigned int ft_gettime(t_info *info)
{
	unsigned int time;
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	time = tp.tv_usec / 1000 + tp.tv_sec * 1000;
	return (time - info->starttime);
}
