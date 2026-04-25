#include "push_swap.h"
#include "libft/libft.h"

void	free_everything(t_list **stack_a, int **input_numbers)
{
	t_list	*copy;

	free(*input_numbers);
	while (*stack_a)
	{
		copy = (*stack_a)->next;
		free(*stack_a);
		*stack_a = copy;
	}
}

int	is_sorted(t_list *stack_a)
{
	while (stack_a->next)
	{
		if (*(int *)stack_a->content > *(int *)(stack_a->next->content))
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	sort_final(t_list **stack_a)
{
	t_node_vars	n;
	t_list		*copy;

	n.pos = 0;
	n.smallest = INT_MAX;
	copy = *stack_a;
	while (copy)
	{
		if (*(int *)copy->content < n.smallest)
		{
			n.smallest = *(int *)copy->content;
			n.final_pos = n.pos;
		}
		n.pos++;
		copy = copy->next;
	}
	if (n.final_pos > (ft_lstsize(*stack_a) / 2))
		n.pos = 0;
	while (*(int *)(*stack_a)->content != n.smallest)
	{
		if (!n.pos)
			rra(stack_a, *stack_a);
		else
			ra(stack_a, *stack_a);
	}
}

int	init_stack(t_list **stack_a, int *input_nums, int arg_count)
{
	t_list	*node;

	if (!input_nums)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	while (arg_count--)
	{
		node = ft_lstnew(&input_nums[arg_count]);
		if (!node)
			return (1);
		ft_lstadd_front(stack_a, node);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list		*stack_a;
	t_list		*stack_b;
	int			arg_count;
	int			*input_numbers;

	stack_a = (NULL);
	stack_b = (NULL);
	input_numbers = parse_input(argc, argv, &arg_count);
	if (init_stack(&stack_a, input_numbers, arg_count)
		|| ft_lstsize(stack_a) == 1)
		return (0);
	if (ft_lstsize(stack_a) == 3)
		sort_three(&stack_a);
	else if (ft_lstsize(stack_a) > 3)
	{
		push_b(&stack_a, &stack_b);
		push_a(&stack_a, &stack_b);
		sort_final(&stack_a);
	}
	else
		if (!is_sorted(stack_a))
			sa(&stack_a);
	free_everything(&stack_a, &input_numbers);
	return (0);
}
