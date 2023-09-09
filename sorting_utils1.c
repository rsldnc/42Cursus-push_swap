/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinc <rdinc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:18:44 by rdinc             #+#    #+#             */
/*   Updated: 2023/09/07 17:11:13 by rdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(int *stack, int size)
{
	int	i;
	int	min;

	i = 0;
	min = stack[i];
	while (i < size)
	{
		if (min > stack[i])
			min = stack[i];
		i++;
	}
	return (min);
}

int	get_min_index(int *stack, int size)
{
	int	i;
	int	index;
	int	min;

	i = 0;
	index = 0;
	min = stack[i];
	while (i < size)
	{
		if (min > stack[i])
		{
			min = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	get_mid_index(int *stack, int size, int current)
{
	int		i;
	int		index;
	long	temp;

	i = 0;
	index = 0;
	temp = 9223372036854775807;
	while (i < size)
	{
		if (stack[i] > current && stack[i] < temp)
		{
			temp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	get_max_index(int *stack, int size)
{
	int	i;
	int	index;
	int	max;

	i = 0;
	index = 0;
	max = stack[i];
	while (i < size)
	{
		if (max < stack[i])
		{
			max = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	get_max(int *stack, int size)
{
	int	i;
	int	max;

	i = 0;
	max = stack[i];
	while (i < size)
	{
		if (max < stack[i])
			max = stack[i];
		i++;
	}
	return (max);
}
