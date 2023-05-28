/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:00:53 by cschmied          #+#    #+#             */
/*   Updated: 2023/05/28 13:00:53 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <philo.h>

int		ft_putstr(const char *str);
int		ft_atoi(const char *str);
int		info_init(int argc, char **argv, t_info *info);
void	ft_wait(long to_wait);
void	*ft_calloc(int count, int size);

long	gettime(t_info *info);
void	free_info(t_info *info);

void	print_message(t_info *info, const char *msg, char* color, int pos);



#endif