/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:17:23 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/11 17:37:40 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	check_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r'
		|| c == '\f' || c == '\v' || c == ' ')
	{
		return (1);
	}
	return (0);
}

static int  ft_isdigit(char c)
{
    if (c <= '9' && c >= '0')
        return (1);
    return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sum;
	int	multiplier;

	sum = 0;
	i = 0;
	multiplier = 1;
	while (check_whitespace(str[i]) == 1)
		i ++;
	if (str[i] == '-')
		return (write(2, "Please only input positive integers.\n", 38),-1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]) != 0)
		i ++;
	while (--i, i >= 0 && ft_isdigit(str[i]) != 0)
	{
		sum += multiplier * (str[i] - '0');
		multiplier *= 10;
	}
	return (sum);
}
