#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include "libft/libft.h"

typedef struct s_node_vars
{
	int	p_cost;
	int	below_med;
	int	pos_a;
	int	pos_b;
	int	smallest;
	int	pos;
	int	final_pos;
}		t_node_vars;

int		input_errors(int argc, char *argv[]);
int		duplicates(int *input, int len);
int		invalid_in_protostack(char **protostack);
void	swap(t_list **head);
void	rotate(t_list **lst, t_list *head);
void	push(t_list **hence_lst, t_list *hence, t_list **hither_lst);
void	reverse_rotate(t_list **lst, t_list *head);
int		*parse_input(int argc, char *argv[], int *arg_count);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	pa(t_list **lst_a, t_list **lst_b, t_list *b);
void	pb(t_list **lst_a, t_list **lst_b, t_list *a);
void	rra(t_list **lst_a, t_list *head_a);
void	rrb(t_list **lst_b, t_list *head_b);
void	rrr(t_list **lst_a, t_list *head_a, t_list **lst_b, t_list *head_b);
void	ra(t_list **lst_a, t_list *head_a);
void	rb(t_list **lst_b, t_list *head_b);
void	rr(t_list **lst_a, t_list *head_a, t_list **lst_b, t_list *head_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
size_t	ft_strlen_skip_zeroes(const char *s);
long	ft_atol(const char *nptr);
int		determine_distance(t_list *lst, int node_val);
int		push_cost(int p_node, int t_node, t_list *p_stack, t_list *t_stack);
void	free_protostack(char ***protostack);
void	pos_rel_median(t_list *lst, int *position, int *below_med, char ab);
void	node_operations(t_list **a, t_list **b, int a_node, int b_node);
void	sort_three(t_list **stack_a);

#endif
