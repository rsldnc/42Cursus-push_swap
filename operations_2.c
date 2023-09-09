/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinc <rdinc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:16:53 by rdinc             #+#    #+#             */
/*   Updated: 2023/09/07 15:52:17 by rdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(int *stack, int size)
{
	int	temp;

	size--;
	temp = stack[size];
	while (size > 0)
	{
		stack[size] = stack[size - 1];
		size--;
	}
	stack[0] = temp;
	write(1, "ra\n", 3);
}

void	rb(int *stack, int size)
{
	int	temp;

	size--;
	temp = stack[size];
	while (size > 0)
	{
		stack[size] = stack[size - 1];
		size--;
	}
	stack[0] = temp;
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_st)
{
	int	size;
	int	temp;

	size = stack_st->size_a - 1;
	temp = stack_st->stack_a[size];
	while (size > 0)
	{
		stack_st->stack_a[size] = stack_st->stack_a[size - 1];
		size--;
	}
	stack_st->stack_a[0] = temp;
	size = stack_st->size_b - 1;
	temp = stack_st->stack_b[size];
	while (size > 0)
	{
		stack_st->stack_b[size] = stack_st->stack_b[size - 1];
		size--;
	}
	stack_st->stack_b[0] = temp;
	write(1, "rr\n", 3);
}
