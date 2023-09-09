/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinc <rdinc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:19:39 by rdinc             #+#    #+#             */
/*   Updated: 2023/09/07 17:11:04 by rdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_cost_in_stack_a(t_stack *stack_st, int curr)
{
	int	cost;
	int	min_i;
	int	mid_i;

	min_i = get_min_index(stack_st->stack_a, stack_st->size_a);
	mid_i = get_mid_index(stack_st->stack_a, stack_st->size_a, curr);
	cost = 0;
	if (curr < get_min(stack_st->stack_a, stack_st->size_a)
		|| curr > get_max(stack_st->stack_a, stack_st->size_a))
	{
		if (min_i >= ((stack_st->size_a - 1) / 2))
			cost += (stack_st->size_a - 1) - min_i;
		else
			cost += min_i + 1;
	}
	else
	{
		if (mid_i >= ((stack_st->size_a - 1) / 2))
			cost += (stack_st->size_a - 1) - mid_i;
		else
			cost += mid_i + 1;
	}
	return (cost);
}

int	find_cheapest_index(t_stack *stack_st)
{
	int		i;
	int		index;
	int		cost;
	long	temp_cost;

	i = 0;
	cost = 0;
	index = 0;
	temp_cost = 9223372036854775807;
	while (i < stack_st->size_b)
	{
		cost += find_cost_in_stack_a(stack_st, stack_st->stack_b[i]);
		if (i >= ((stack_st->size_b - 1) / 2))
			cost += (stack_st->size_b - 1) - i;
		else
			cost += i + 1;
		if (temp_cost > cost)
		{
			temp_cost = cost;
			index = i;
		}
		cost = 0;
		i++;
	}
	return (index);
}

void	get_to_top_a(t_stack *stack_st, int i)
{
	if (i >= ((stack_st->size_a - 1) / 2))
	{
		while (i < (stack_st->size_a - 1))
		{
			ra(stack_st->stack_a, stack_st->size_a);
			i++;
		}
	}
	else
	{
		while (i >= 0)
		{
			rra(stack_st->stack_a, stack_st->size_a);
			i--;
		}
	}
}

void	get_to_top_b(t_stack *stack_st, int ci)
{
	if (ci >= ((stack_st->size_b - 1) / 2))
	{
		while (ci < ((stack_st->size_b - 1)))
		{
			rb(stack_st->stack_b, stack_st->size_b);
			ci++;
		}
	}
	else
	{
		while (ci >= 0)
		{
			rrb(stack_st->stack_b, stack_st->size_b);
			ci--;
		}
	}
}

void	perform_for_cheapest(t_stack *stack_st, int ci)
{
	int	current;
	int	i;

	i = 0;
	current = stack_st->stack_b[ci];
	if (current > get_max(stack_st->stack_a, stack_st->size_a)
		|| current < get_min(stack_st->stack_a, stack_st->size_a))
	{
		i = get_min_index(stack_st->stack_a, stack_st->size_a);
		get_to_top_a(stack_st, i);
		get_to_top_b(stack_st, ci);
		pa(stack_st);
	}
	else
	{
		i = get_mid_index(stack_st->stack_a, stack_st->size_a, current);
		get_to_top_a(stack_st, i);
		get_to_top_b(stack_st, ci);
		pa(stack_st);
	}
}
