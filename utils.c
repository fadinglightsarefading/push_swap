#include "push_swap.h"
#include "libft/libft.h"

size_t	ft_strlen_skip_zeroes(const char *s)
{
	int	i;

	while (*s == '0')
		s++;
	i = 0;
	while (*s++)
		i++;
	return (i);
}

static const char	*ft_atol_two(const char *nptr, int *pluses)
{
	*pluses = 0;
	while (*nptr == ' ' || *nptr == '+' || (*nptr >= 9 && *nptr <= 13))
	{
		if (*nptr >= 9 && *nptr <= 13 && *pluses)
			return (0);
		if (*nptr == '+')
			(*pluses)++;
		nptr++;
	}
	return (nptr);
}

long	ft_atol(const char *nptr)
{
	int		negate;
	int		pluses;
	long	final;

	negate = 1;
	final = 0;
	nptr = ft_atol_two(nptr, &pluses);
	if (!nptr)
		return (0);
	if (*nptr == '-')
	{
		if (pluses > 0)
			return (0);
		negate = -negate;
		nptr++;
	}
	if (pluses < 2)
		while (*nptr >= '0' && *nptr <= '9')
			final = final * 10 + (*nptr++ - 48);
	return ((final * negate));
}

int	determine_distance(t_list *lst, int node_val)
{
	int	distance;

	distance = 0;
	while (*(int *)lst->content != node_val && lst)
	{
		distance++;
		lst = lst->next;
	}
	return (distance);
}

int	push_cost(int p_node, int t_node, t_list *p_stack, t_list *t_stack)
{
	int	cost_a;
	int	cost_b;
	int	final_cost;
	int	below_med;

	below_med = 0;
	cost_a = determine_distance(p_stack, p_node);
	if (cost_a > (ft_lstsize(p_stack) / 2))
	{
		below_med++;
		cost_a = ft_lstsize(p_stack) - cost_a;
	}
	cost_b = determine_distance(t_stack, t_node);
	if (cost_b > (ft_lstsize(t_stack) / 2))
	{
		below_med += 2;
		cost_b = ft_lstsize(t_stack) - cost_b;
	}
	if (cost_a == cost_b && (!below_med || below_med == 3))
		final_cost = cost_a;
	else
		final_cost = cost_a + cost_b;
	return (final_cost);
}
