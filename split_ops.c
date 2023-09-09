/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinc <rdinc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:20:28 by rdinc             #+#    #+#             */
/*   Updated: 2023/09/09 13:11:42 by rdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_init_stacks(t_stack **stack_st, int len)
{
	(*stack_st) = malloc(sizeof(t_stack));
	if (!(*stack_st))
		ft_error((*stack_st));
	(*stack_st)->stack_a = malloc(sizeof(int) * (len));
	(*stack_st)->stack_b = malloc(sizeof(int) * (len));
	if (!(*stack_st)->stack_a || !(*stack_st)->stack_b)
		ft_error((*stack_st));
	(*stack_st)->size_a = 0;
	(*stack_st)->size_b = 0;
}

int	split_len(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

t_stack	*split_and_check(char **argv)
{
	t_stack	*stack_st;
	char	**split;
	int		i;
	int		slen;

	stack_st = NULL;
	if (argv[1][0] == '\0' || is_empty(argv[1]))
		ft_error(stack_st);
	split = ft_split(argv[1], ' ');
	slen = split_len(split);
	i = 0;
	split_init_stacks(&stack_st, slen);
	while (split[i])
	{
		stack_st->size_a++;
		stack_st->stack_a[i] = ft_atol(split[slen - i - 1], stack_st);
		i++;
	}
	while (i >= 0)
		free(split[i--]);
	free(split);
	return (stack_st);
}
