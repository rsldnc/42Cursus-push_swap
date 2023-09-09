/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdinc <rdinc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:12:15 by rdinc             #+#    #+#             */
/*   Updated: 2023/09/09 13:11:27 by rdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	*stack_a;
	int	size_a;
	int	*stack_b;
	int	size_b;
}	t_stack;

void	sa(int *stack, int size);
void	sb(int *stack, int size);
void	ss(t_stack *stack_st);
void	pa(t_stack *stack_st);
void	pb(t_stack *stack_st);
void	ra(int *stack, int size);
void	rb(int *stack, int size);
void	rr(t_stack *stack_st);
void	rra(int *stack, int size);
void	rrb(int *stack, int size);
void	rrr(t_stack *stack_st);

void	sort_3nums(t_stack *stack_st);
void	sort_4nums(t_stack *stack_st);
void	sort_5nums(t_stack *stack_st);
void	big_sort(t_stack *stack_st);

int		get_min(int *stack, int size);
int		get_min_index(int *stack, int size);
int		get_mid_index(int *stack, int size, int current);
int		get_max_index(int *stack, int size);
int		get_max(int *stack, int size);
int		find_cost_in_stack_a(t_stack *stack_st, int curr);
int		find_cheapest_index(t_stack *stack_st);
void	get_to_top_a(t_stack *stack_st, int i);
void	get_to_top_b(t_stack *stack_st, int ci);
void	perform_for_cheapest(t_stack *stack_st, int ci);

void	args_init_stacks(t_stack **stack_st, int argc);
t_stack	*args_and_check(int argc, char **argv);
char	**connect_args(int argc, char **argv, t_stack *stack_st);

void	ft_error(t_stack *stack_st);
void	check_duplicates(t_stack *stacks);
t_stack	*check_and_initialize(int argc, char **argv);
void	check_result(long result, t_stack *stack_st);

int		is_sorted(t_stack *stack_st);
void	sorting_manager(t_stack *stack_st);

void	split_init_stacks(t_stack **stack_st, int len);
int		split_len(char **split);
t_stack	*split_and_check(char **argv);

long	ft_atol(const char *str, t_stack *stack_st);
void	free_all(t_stack *stack_st);
int		is_empty(char *str);

#endif
