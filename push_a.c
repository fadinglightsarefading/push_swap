#include "push_swap.h"
#include "libft/libft.h"

int	stack_a_smaller(int node_val, t_list *stack_a)
{
	while (stack_a)
	{
		if (node_val < *(int *)stack_a->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	determine_a_t_node(int push_node, int target_node, t_list *stack_a)
{
	int		flag;
	t_list	*a;

	flag = 0;
	a = stack_a;
	while (a)
	{
		if (stack_a_smaller(push_node, stack_a))
		{
			if (*(int *)a->content < target_node)
				target_node = *(int *)a->content;
		}
		else if (!flag && *(int *)a->content > push_node
			&& *(int *)a->content >= target_node)
		{
			flag++;
			target_node = *(int *)a->content;
		}
		else if (flag && *(int *)a->content > push_node
			&& *(int *)a->content < target_node)
			target_node = *(int *)a->content;
		a = a->next;
	}
	return (target_node);
}

void	cheapest_a_push(t_list *a, t_list *b, int *fin_push, int *fin_target)
{
	int		push_nodes;
	int		target_nodes;
	t_list	*cycle_stack_b;

	push_nodes = *(int *)b->content;
	target_nodes = *(int *)a->content;
	cycle_stack_b = b;
	*fin_push = *(int *)b->content;
	*fin_target = determine_a_t_node(push_nodes, target_nodes, a);
	while (cycle_stack_b)
	{
		push_nodes = *(int *)cycle_stack_b->content;
		target_nodes = *(int *)a->content;
		target_nodes = determine_a_t_node(push_nodes, target_nodes, a);
		if (push_cost(*fin_push, *fin_target, b, a)
			> push_cost(push_nodes, target_nodes, b, a))
		{
			*fin_push = push_nodes;
			*fin_target = target_nodes;
		}
		cycle_stack_b = cycle_stack_b->next;
	}
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	int	push_node;
	int	target_node;

	while (ft_lstsize(*stack_b))
	{
		cheapest_a_push(*stack_a, *stack_b, &push_node, &target_node);
		node_operations(stack_a, stack_b, target_node, push_node);
		pa(stack_a, stack_b, *stack_b);
	}
}
