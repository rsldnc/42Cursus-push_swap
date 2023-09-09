/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinc <rdinc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:11:46 by rdinc             #+#    #+#             */
/*   Updated: 2023/09/09 13:10:05 by rdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	args_init_stacks(t_stack **stack_st, int argc)
{
	(*stack_st) = malloc(sizeof(t_stack));
	if (!(*stack_st))
		ft_error((*stack_st));
	(*stack_st)->stack_a = malloc(sizeof(int) * (argc));
	(*stack_st)->stack_b = malloc(sizeof(int) * (argc));
	if (!(*stack_st)->stack_a || !(*stack_st)->stack_b)
		ft_error((*stack_st));
	(*stack_st)->size_a = 0;
	(*stack_st)->size_b = 0;
}

t_stack	*args_and_check(int argc, char **argv)
{
	t_stack	*stack_st;
	int		i;

	stack_st = NULL;
	args_init_stacks(&stack_st, argc);
	i = 0;
	while (i < argc)
	{
		stack_st->size_a++;
		stack_st->stack_a[i] = ft_atol(argv[argc - i - 1], stack_st);
		i++;
	}
	while (i >= 0)
	{
		free(argv[i]);
		i--;
	}
	free(argv);
	return (stack_st);
}

char	**connect_args(int argc, char **argv, t_stack *stack_st)
{
	char	**to_return;
	char	*string;
	int		i;

	i = 1;
	string = malloc(sizeof(1));
	string[0] = '\0';
	while (i < argc)
	{
		if (is_empty(argv[i]))
			ft_error(stack_st);
		string = ft_strjoin(string, " ");
		string = ft_strjoin(string, argv[i]);
		i++;
	}
	to_return = ft_split(string, ' ');
	free(string);
	return (to_return);
}
