/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:24:31 by cschmied          #+#    #+#             */
/*   Updated: 2023/05/30 21:19:26 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static long	get_starttime(void);
static void	end_game(t_info *info);

int	main(int argc, char **argv)
{
	t_info	info;

	if (info_init(argc, argv, &info) == FAILURE)
		return (1);
	info.starttime = get_starttime();
	pthread_mutex_unlock(&info.start_lock);
	while (1)
	{
		if (check_state(&info) == TRUE)
			break ;
		usleep(10);
	}
	join_threads(&info);
	end_game(&info);
	return (SUCCESS);
}

static long	get_starttime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

static void	end_game(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philos)
	{
		pthread_detach(info->philos[i].thread);
		i ++;
	}
	free_info(info);
}
