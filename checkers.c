/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinc <rdinc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:13:38 by rdinc             #+#    #+#             */
/*   Updated: 2023/09/09 13:10:33 by rdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stack *stack_st)
{
	write(2, "Error\n", 6);
	free_all(stack_st);
	exit(1);
}

void	check_duplicates(t_stack *stack_st)
{
	int	i;
	int	j;

	i = 0;
	while (i < (stack_st->size_a - 1))
	{
		j = i + 1;
		while (j < stack_st->size_a)
		{
			if (stack_st->stack_a[i] == stack_st->stack_a[j])
				ft_error(stack_st);
			j++;
		}
		i++;
	}
}

t_stack	*check_and_initialize(int argc, char **argv)
{
	t_stack	*stack_st;
	int		new_argc;
	char	**new_argv;

	stack_st = NULL;
	new_argv = NULL;
	new_argc = 0;
	if (argc < 2)
		ft_error(stack_st);
	else if (argc == 2)
		stack_st = split_and_check(argv);
	else if (argc > 2)
	{
		new_argv = connect_args(argc, argv, stack_st);
		new_argc = split_len(new_argv);
		stack_st = args_and_check(new_argc, new_argv);
	}
	check_duplicates(stack_st);
	return (stack_st);
}

void	check_result(long result, t_stack *stack_st)
{
	if (result > 2147483647 || result < -2147483648)
		ft_error(stack_st);
}
