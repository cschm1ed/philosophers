/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:54:21 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/11 18:01:26 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void    clean_table(t_table *table)
{
    if (table->fork_states)
        free(table->fork_states);
    if (table->philos)
        free(table->philos);
}

void    try_clean(t_info *info)
{
    clean_table(&info->table);
}