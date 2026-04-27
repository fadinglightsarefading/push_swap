/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:36:46 by cclarke           #+#    #+#             */
/*   Updated: 2026/04/27 13:36:47 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	free_protostack(char ***protostack)
{
	int	i;

	i = -1;
	while ((*protostack)[++i])
		free((*protostack)[i]);
	free(*protostack);
}

void	pos_rel_median(t_list *lst, int *position, int *below_med, char ab)
{
	if (*position > (ft_lstsize(lst) / 2))
	{
		if (ab == 'a')
			(*below_med)++;
		else if (ab == 'b')
			(*below_med) += 2;
		*position = ft_lstsize(lst) - *position;
	}
}

void	node_operations(t_list **a, t_list **b, int a_node, int b_node)
{
	t_node_vars	n;

	n.p_cost = push_cost(a_node, b_node, *a, *b);
	while (n.p_cost--)
	{
		n.below_med = 0;
		n.pos_a = determine_distance(*a, a_node);
		pos_rel_median(*a, &n.pos_a, &n.below_med, 'a');
		n.pos_b = determine_distance(*b, b_node);
		pos_rel_median(*b, &n.pos_b, &n.below_med, 'b');
		if (n.pos_a == 0 && n.pos_b == 0)
			return ;
		else if (n.pos_a == n.pos_b && !n.below_med)
			rr(a, *a, b, *b);
		else if (n.pos_a == n.pos_b && n.below_med == 3)
			rrr(a, *a, b, *b);
		else if (n.pos_a && !n.below_med)
			ra(a, *a);
		else if (n.pos_a && (n.below_med == 1 || n.below_med == 3))
			rra(a, *a);
		else if (n.pos_b && !n.below_med)
			rb(b, *b);
		else if (n.pos_b && (n.below_med == 2 || n.below_med == 3))
			rrb(b, *b);
	}
}

void	sort_three(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*stack_a)->content;
	second = *(int *)((*stack_a)->next->content);
	third = *(int *)((*stack_a)->next->next->content);
	if (first > second && second < third && third > first)
		sa(stack_a);
	else if (first < second && second > third && third < first)
		rra(stack_a, *stack_a);
	else if (first < second && second > third && third > first)
	{
		rra(stack_a, *stack_a);
		sa(stack_a);
	}
	else if (first > second && second < third && third < first)
		ra(stack_a, *stack_a);
	else if (first > second && second > third && third < first)
	{
		ra(stack_a, *stack_a);
		sa(stack_a);
	}
}
