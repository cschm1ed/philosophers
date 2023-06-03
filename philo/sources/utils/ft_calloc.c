/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:12:08 by cschmied          #+#    #+#             */
/*   Updated: 2023/04/22 18:25:21 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*ft_calloc(int count, int size)
{
	void	*ptr;
	int		i;

	i = 0;
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	memset(ptr, 0, size * count);
	return (ptr);
}
