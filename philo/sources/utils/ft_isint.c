/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 08:24:01 by cschmied          #+#    #+#             */
/*   Updated: 2023/06/03 08:24:01 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

#define MAX "2147483647"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i ++;
	return (i);
}

int	ft_isint(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > ft_strlen(MAX)
		|| *str == '-')
		return (FALSE);
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (FALSE);
		i ++;
	}
	i = 0;
	if (ft_strlen(str) == ft_strlen(MAX))
	{
		while (str[i])
		{
			if (str[i] > MAX[i])
				return (FALSE);
			i ++;
		}
	}
	return (TRUE);
}
