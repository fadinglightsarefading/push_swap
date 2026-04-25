#include "push_swap.h"
#include "libft/libft.h"

void	pa(t_list **lst_a, t_list **lst_b, t_list *b)
{
	push(lst_b, b, lst_a);
	ft_printf("pa\n");
}

void	pb(t_list **lst_a, t_list **lst_b, t_list *a)
{
	push(lst_a, a, lst_b);
	ft_printf("pb\n");
}
