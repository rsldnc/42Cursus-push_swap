/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customsorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinc <rdinc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:14:16 by rdinc             #+#    #+#             */
/*   Updated: 2023/09/07 13:04:26 by rdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3nums(t_stack *stack_st)
{
	int	max_i;

	max_i = get_max_index(stack_st->stack_a, stack_st->size_a);
	if (max_i == 0)
	{
		if (stack_st->stack_a[2] > stack_st->stack_a[1])
			sa(stack_st->stack_a, stack_st->size_a);
	}
	else if (max_i == 1)
	{
		rra(stack_st->stack_a, stack_st->size_a);
		if (stack_st->stack_a[2] > stack_st->stack_a[1])
			sa(stack_st->stack_a, stack_st->size_a);
	}
	else
	{
		ra(stack_st->stack_a, stack_st->size_a);
		if (stack_st->stack_a[2] > stack_st->stack_a[1])
			sa(stack_st->stack_a, stack_st->size_a);
	}
}

void	sort_4nums(t_stack *stack_st)
{
	int	min_i;

	min_i = get_min_index(stack_st->stack_a, stack_st->size_a);
	if (min_i >= 2)
	{
		while (min_i < (stack_st->size_a - 1))
		{
			ra(stack_st->stack_a, stack_st->size_a);
			min_i++;
		}
	}
	else
	{
		while (min_i >= 0)
		{
			rra(stack_st->stack_a, stack_st->size_a);
			min_i--;
		}
	}
	pb(stack_st);
	sort_3nums(stack_st);
	pa(stack_st);
}

void	sort_5nums(t_stack *stack_st)
{
	int	min_i;

	min_i = get_min_index(stack_st->stack_a, stack_st->size_a);
	if (min_i >= 2)
	{
		while (min_i < (stack_st->size_a - 1))
		{
			ra(stack_st->stack_a, stack_st->size_a);
			min_i++;
		}
	}
	else
	{
		while (min_i >= 0)
		{
			rra(stack_st->stack_a, stack_st->size_a);
			min_i--;
		}
	}
	pb(stack_st);
	sort_4nums(stack_st);
	pa(stack_st);
}

void	big_sort(t_stack *stack_st)
{
	int	cheap_index;
	int	max_i;

	while (stack_st->size_a > 5)
		pb(stack_st);
	sort_5nums(stack_st);
	while (stack_st->size_b > 0)
	{
		cheap_index = find_cheapest_index(stack_st);
		perform_for_cheapest(stack_st, cheap_index);
	}
	max_i = get_max_index(stack_st->stack_a, stack_st->size_a);
	if (max_i >= ((stack_st->size_a - 1) / 2))
	{
		while (!is_sorted(stack_st))
			ra(stack_st->stack_a, stack_st->size_a);
	}
	else
	{
		while (!is_sorted(stack_st))
			rra(stack_st->stack_a, stack_st->size_a);
	}
}
