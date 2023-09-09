/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinc <rdinc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:21:12 by rdinc             #+#    #+#             */
/*   Updated: 2023/09/09 13:12:00 by rdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str, t_stack *stack_st)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!str[i])
		ft_error(stack_st);
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i++] - 48);
		check_result(num, stack_st);
	}
	if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		ft_error(stack_st);
	return (num * sign);
}

void	free_all(t_stack *stack_st)
{
	if (stack_st)
	{
		free(stack_st->stack_a);
		stack_st->stack_a = NULL;
		free(stack_st->stack_b);
		stack_st->stack_b = NULL;
		free(stack_st);
		stack_st = NULL;
	}
}

int	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
