/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinc <rdinc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:15:24 by rdinc             #+#    #+#             */
/*   Updated: 2023/09/07 15:51:39 by rdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *stack, int size)
{
	int	temp;

	temp = stack[size - 1];
	stack[size - 1] = stack[size - 2];
	stack[size - 2] = temp;
	write(1, "sa\n", 3);
}

void	sb(int *stack, int size)
{
	int	temp;

	temp = stack[size - 1];
	stack[size - 1] = stack[size - 2];
	stack[size - 2] = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_st)
{
	int	size;
	int	temp;

	size = stack_st->size_a;
	temp = stack_st->stack_a[size - 1];
	stack_st->stack_a[size - 1] = stack_st->stack_a[size - 2];
	stack_st->stack_a[size - 2] = temp;
	size = stack_st->size_b;
	temp = stack_st->stack_b[size - 1];
	stack_st->stack_b[size - 1] = stack_st->stack_b[size - 2];
	stack_st->stack_b[size - 2] = temp;
	write(1, "ss\n", 3);
}

void	pa(t_stack *stack_st)
{
	int	temp;

	temp = stack_st->stack_b[stack_st->size_b - 1];
	stack_st->size_b--;
	stack_st->size_a++;
	stack_st->stack_a[stack_st->size_a - 1] = temp;
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_st)
{
	int	temp;

	temp = stack_st->stack_a[stack_st->size_a - 1];
	stack_st->size_a--;
	stack_st->size_b++;
	stack_st->stack_b[stack_st->size_b - 1] = temp;
	write(1, "pb\n", 3);
}
