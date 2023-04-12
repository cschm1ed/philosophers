/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:21:16 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/12 15:18:01 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void    *philosopher(void *arg)
{
    t_info  *str;

    str = (t_info*)(arg);
    pthread_mutex_lock(&str->start_game);
    pthread_mutex_unlock(&str->start_game);
    printf("time to play the game\n");
    printf("muhahahahah\n");
    return (NULL);
}

int main(int argc, char **argv)
{
    t_info      info;

	if (info_init(argc, argv, &info) == -1 ||
		table_init(&info, info.table) == -1)
		return (1);
    return (0);
}
