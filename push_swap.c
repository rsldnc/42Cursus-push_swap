/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinc <rdinc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:11:09 by rdinc             #+#    #+#             */
/*   Updated: 2023/09/06 18:10:00 by rdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack_st)
{
	int	i;
	int	j;

	i = 0;
	while (i < (stack_st->size_a - 1))
	{
		j = i + 1;
		while (j < stack_st->size_a)
		{
			if (stack_st->stack_a[i] < stack_st->stack_a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	sorting_manager(t_stack *stack_st)
{
	if (is_sorted(stack_st))
	{
		free_all(stack_st);
		exit(1);
	}
	else if (stack_st->size_a == 2)
		sa(stack_st->stack_a, stack_st->size_a);
	else if (stack_st->size_a == 3)
		sort_3nums(stack_st);
	else if (stack_st->size_a == 4)
		sort_4nums(stack_st);
	else if (stack_st->size_a == 5)
		sort_5nums(stack_st);
	else
		big_sort(stack_st);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_st;

	if (argc >= 2)
	{
		stack_st = check_and_initialize(argc, argv);
		sorting_manager(stack_st);
		free_all(stack_st);
	}
	return (0);
}
