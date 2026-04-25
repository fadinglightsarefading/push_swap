#include "push_swap.h"
#include "libft/libft.h"

void	ra(t_list **lst_a, t_list *head_a)
{
	rotate(lst_a, head_a);
	ft_printf("ra\n");
}

void	rb(t_list **lst_b, t_list *head_b)
{
	rotate(lst_b, head_b);
	ft_printf("rb\n");
}

void	rr(t_list **lst_a, t_list *head_a, t_list **lst_b, t_list *head_b)
{
	rotate(lst_a, head_a);
	rotate(lst_b, head_b);
	ft_printf("rr\n");
}
