/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinc <rdinc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:17:27 by rdinc             #+#    #+#             */
/*   Updated: 2023/09/07 15:52:58 by rdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(int *stack, int size)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack[i];
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = temp;
	write(1, "rra\n", 4);
}

void	rrb(int *stack, int size)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack[i];
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = temp;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_st)
{
	int	size;
	int	i;
	int	temp;

	size = stack_st->size_a;
	i = 0;
	temp = stack_st->stack_a[i];
	while (i < size - 1)
	{
		stack_st->stack_a[i] = stack_st->stack_a[i + 1];
		i++;
	}
	stack_st->stack_a[size - 1] = temp;
	size = stack_st->size_b;
	i = 0;
	temp = stack_st->stack_b[i];
	while (i < size - 1)
	{
		stack_st->stack_b[i] = stack_st->stack_b[i + 1];
		i++;
	}
	stack_st->stack_b[size - 1] = temp;
	write(1, "rrr\n", 4);
}
