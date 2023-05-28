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

static int ft_isdigit(const char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	long long	sum;
	int	i;

	i = 0;
	sum = 0;
	while (iswhitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		sum = sum * 10 + (str[i] - '0');
		if (sum > INT_MAX)
			return (-1);
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return ((int)sum);
}

