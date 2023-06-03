/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:03:12 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/03 11:14:03 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
static int	join_threads(t_info *info);
static int	one_philo(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_info	info;

	if (one_philo(argc, argv) == TRUE)
		return (0);
	if (info_init(argc, argv, &info) == FAILURE)
		return (1);
	info.starttime = get_starttime();
	pthread_mutex_unlock(&info.start_lock);
	while (1)
	{
		if (check_state(&info) == TRUE)
			break ;
		usleep(PAUSE_CHECK);
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

static int	join_threads(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philos)
	{
		if (pthread_join(info->philos[i].thread, NULL) != 0)
			return (FAILURE);
		i ++;
	}
	return (SUCCESS);
}

static int	one_philo(int argc, char **argv)
{
	if (!(argc == 5 || argc == 6))
		return (FALSE);
	if (ft_isint(argv[2]) == TRUE && ft_atoi(argv[2]) == 1)
	{
		if (ft_isint(argv[3]) == FALSE)
				return (FALSE);
		printf("CYAN0 1 has taken a fork\nRESET");
		ft_wait(ft_atoi(argv[3]));
		printf("RED%d, 1 has died\nRESET", ft_atoi(argv[3]));
		return (TRUE);
	}
	return (FALSE);
}

