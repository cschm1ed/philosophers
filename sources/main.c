/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:48:33 by cschmied          #+#    #+#             */
/*   Updated: 2023/05/14 16:48:33 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int			info_init(int argc, char **argv, t_info *info);
static int			create_threads(t_info *info);
static unsigned int	set_starttime(void);
/*static int 			check_for_dead(t_info *info);*/

/*static int			check_for_dead(t_info *info)
{
	int 	i;
		*current;

	i = 0;
	while (i < info->num_philos)
	{

	}
}*/

static unsigned int	set_starttime(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return (tp.tv_usec / 1000 + tp.tv_sec * 1000);
}

int main(int argc, char **argv)
{
	t_info	info;

	pthread_mutex_init(&info.start, NULL);
	pthread_mutex_lock(&info.start);
	info.has_died = FALSE;
	if (info_init(argc, argv, &info) == FAILURE)
		return (1);
	info.starttime = set_starttime();
	/*pthread_mutex_unlock(&info.start);*/
	while (1)
	{
		pthread_mutex_lock(&info.state_lock);
		if (info.has_died == TRUE)
			return (1);
		pthread_mutex_unlock(&info.state_lock);
	}
/*	while (i < info.num_philos)
	{
		pthread_join(info.threads[i], NULL);
		i ++;
	}*/
	return (0);
}

static int info_init(int argc, char **argv, t_info *info)
{
	if (argc > 6)
	{
		printf("ERROR, Usage: ");
		printf("'./philo <num_philos> <time_to_die> <time_to_sleep> <num_to_eat>\n");
		return (FAILURE);
	}
	info->num_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->forks = ft_calloc(info->num_philos, sizeof(pthread_mutex_t));
	if (info->forks == NULL)
		return (FAILURE);
	if (argc == 6)
		info->count_to_eat = ft_atoi(argv[5]);
	info->threads = ft_calloc(sizeof(pthread_t), info->num_philos);
	if (info->threads == NULL)
		return (FAILURE);
	pthread_mutex_init(&info->state_lock, NULL);
	if (create_threads(info) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int	create_threads(t_info *info)
{
	int 	i;
	t_philo *philo;

	i = 0;
	while (i < info->num_philos)
	{
		philo = malloc(sizeof(t_philo));
		if (philo == NULL)
			return (FAILURE);
		philo->pos = i;
		philo->info = info;
		if (pthread_create(&(info->threads[i]), NULL, philosopher, philo) != 0)
			return (perror("pthread"), FAILURE); // free threads
		i ++;
	}
	return (SUCCESS);
}

void	*philosopher(void *arg)
{
	t_info	*info;
	t_philo	*philo;
	philo = (t_philo *)arg;

	info = philo->info;
	printf(BLUE"starting thread: %d\n", philo->pos);

	pthread_mutex_lock(&(info->start));
	pthread_mutex_unlock(&(info->start));

	usleep(info->time_to_die * 1000);

	pthread_mutex_lock(&info->state_lock);
	if (info->has_died == FALSE)
		printf(RED"%d philo: %d has died\n"ESC, ft_gettime(info), philo->pos);
	info->has_died = TRUE;
	pthread_mutex_unlock(&info->state_lock);
	return (arg);
}
