/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:33:11 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/22 18:03:19 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	iswhitespace(const char c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\f' || c == '\v');
}

static int	smaller_int_max(const char *str)
{
	char	max[11] = "2147483647";
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] > max[i])
			return (0);
		i ++;
	}
	return (1);
}

static int	ispositiveint(const char *str)
{
	int	i;
	int	cp;

	cp = 0;
	i = 0;
	while (str[i])
	{
		if (!iswhitespace(str[i]) && (str[i] < '0' && str[i] > '9')
			&& str[i] != '+')
			return (0);
		if (str[i] == '+')
		{
			cp ++;
			if (cp > 1)
				return (0);
		}
		i ++;
	}
	i = 0;
	while (iswhitespace(str[i]))
		i ++;
	return (smaller_int_max(str + i));
}

int	ft_atoi(const char *str)
{
	int	sum;
	int	multiplier;
	int	i;

	i = 0;
	sum = 0;
	multiplier = 1;
	if (!ispositiveint(str))
		return (-1);
	while (str[i])
		i++;
	while (--i >= 0)
	{
		sum += (str[i] - '0') * multiplier;
		multiplier *= 10;
	}
	return (sum);
}
