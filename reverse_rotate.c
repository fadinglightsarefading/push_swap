/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarke <cclarke@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:36:04 by cclarke           #+#    #+#             */
/*   Updated: 2026/04/27 13:36:11 by cclarke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	rra(t_list **lst_a, t_list *head_a)
{
	reverse_rotate(lst_a, head_a);
	ft_printf("rra\n");
}

void	rrb(t_list **lst_b, t_list *head_b)
{
	reverse_rotate(lst_b, head_b);
	ft_printf("rrb\n");
}

void	rrr(t_list **lst_a, t_list *head_a, t_list **lst_b, t_list *head_b)
{
	reverse_rotate(lst_a, head_a);
	reverse_rotate(lst_b, head_b);
	ft_printf("rrr\n");
}
