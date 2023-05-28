/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:24:31 by cschmied          #+#    #+#             */
/*   Updated: 2023/05/28 16:24:31 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static long get_starttime(void);
static int	check_dead(t_info *info);
static int	check_times_eaten(t_info *info);
static void	end_game(t_info *info);

int main(int argc, char **argv)
{
	t_info		info;

	if (info_init(argc, argv, &info) == FAILURE)
		return (1);
	info.starttime = get_starttime();
	pthread_mutex_unlock(&info.start_lock);
	while (1)
	{
		if (check_dead(&info) == TRUE
			|| (argc > 5 && check_times_eaten(&info) == TRUE))
			break ;
		usleep(100);
	}
	join_threads(&info);
	end_game(&info);
	return (SUCCESS);
}

static long get_starttime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

static int	check_times_eaten(t_info *info)
{
	int i;

	i = 0;
	pthread_mutex_lock(&info->times_eaten_lock);
	while (i < info->num_philos)
	{
		if (info->times_eaten[i] != info->times_to_eat)
			return (FALSE);
		i ++;
	}
	pthread_mutex_lock(&info->times_eaten_lock);
	return (TRUE);
}

static int	check_dead(t_info *info)
{
	int i;

	i = 0;
	pthread_mutex_lock(&info->times_eaten_lock);
	while (i < info->num_philos)
	{
		if (gettime(info) - info->philos[i].time_last_eaten
			>= info->time_to_die)
		{
			pthread_mutex_lock(&info->finished_lock);
			info->died = TRUE;
			pthread_mutex_unlock(&info->finished_lock);
			print_died(info, i);
			return (TRUE);
		}
		i ++;
	}
	pthread_mutex_unlock(&info->times_eaten_lock);
	return (FALSE);
}

static void	end_game(t_info *info)
{
	int i;

	i = 0;
	info->died = TRUE;
	while (i < info->num_philos)
	{
		pthread_detach(info->philos[i].thread);
		i ++;
	}
	free_info(info);
}
