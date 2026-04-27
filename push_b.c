/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:35:32 by cclarke           #+#    #+#             */
/*   Updated: 2026/04/27 13:35:34 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	stack_b_greater(int node_val, t_list *stack_b)
{
	while (stack_b)
	{
		if (node_val > *(int *)stack_b->content)
			return (0);
		stack_b = stack_b->next;
	}
	return (1);
}

int	determine_b_t_node(int push_node, int target_node, t_list *stack_b)
{
	int		flag;
	t_list	*b;

	flag = 0;
	b = stack_b;
	while (b)
	{
		if (stack_b_greater(push_node, stack_b))
		{
			if (*(int *)b->content > target_node)
				target_node = *(int *)b->content;
		}
		else if (!flag && *(int *)b->content < push_node
			&& *(int *)b->content <= target_node)
		{
			flag++;
			target_node = *(int *)b->content;
		}
		else if (flag && *(int *)b->content < push_node
			&& *(int *)b->content > target_node)
			target_node = *(int *)b->content;
		b = b->next;
	}
	return (target_node);
}

void	cheapest_b_push(t_list *a, t_list *b, int *fin_push, int *fin_target)
{
	int		push_nodes;
	int		target_nodes;
	t_list	*cycle_stack_a;

	push_nodes = *(int *)a->content;
	target_nodes = *(int *)b->content;
	cycle_stack_a = a;
	*fin_push = *(int *)a->content;
	*fin_target = determine_b_t_node(push_nodes, target_nodes, b);
	while (cycle_stack_a)
	{
		push_nodes = *(int *)cycle_stack_a->content;
		target_nodes = *(int *)b->content;
		target_nodes = determine_b_t_node(push_nodes, target_nodes, b);
		if (push_cost(*fin_push, *fin_target, a, b)
			> push_cost(push_nodes, target_nodes, a, b))
		{
			*fin_push = push_nodes;
			*fin_target = target_nodes;
		}
		cycle_stack_a = cycle_stack_a->next;
	}
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	int	push_node;
	int	target_node;

	if (ft_lstsize(*stack_a) == 4)
		pb(stack_a, stack_b, *stack_a);
	else
	{
		pb(stack_a, stack_b, *stack_a);
		pb(stack_a, stack_b, *stack_a);
		while (ft_lstsize(*stack_a) > 3)
		{
			cheapest_b_push(*stack_a, *stack_b, &push_node, &target_node);
			node_operations(stack_a, stack_b, push_node, target_node);
			pb(stack_a, stack_b, *stack_a);
		}
	}
	sort_three(stack_a);
}
